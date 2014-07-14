package com.ehmanu.rtcompanionjpo;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.FragmentManager;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

/**
 ** Created by chambo_e on 7/3/14.
 **/
 public class AddObj extends DialogFragment {

    private Object existing = null;
    private boolean exist = false;
    private EditText editX, editY, editZ,
            editRot_X, editRot_Y, editRot_Z,
            effect, shine;
    public static EditText editR, editG, editB, angle, rayon;
    private Spinner Spinner_obj;
    private Spinner Spinner_noise;
    public static final String sep = ";";
    private String title;
    private int pos;

    private AddObj(String title) {
        this.title = title;
    }

    private AddObj(Object obj, int pos, String title) {
        this.existing = obj;
        this.exist = true;
        this.title = title;
        this.pos = pos;
    }

    public static AddObj newInstance(String title) {
        return new AddObj(title);
    }

    public static AddObj newInstance(Object obj, int pos, String title) {
        return new AddObj(obj, pos, title);
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        AlertDialog.Builder dial = new AlertDialog.Builder(getActivity())
                .setTitle(title)
                .setPositiveButton("OK",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                if (exist)
                                    set_obj();
                                else
                                    handle_send();
                            }
                        }
                )
                .setNegativeButton("Cancel",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                dialog.dismiss();
                            }
                        }
                );
        if (exist)
            dial.setNeutralButton("Delete", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    ChObjDialog.objects.remove(pos);
                    ChObjDialog.objectAdapter.notifyDataSetChanged();
                    dismiss();
                }
            });
        LayoutInflater i = getActivity().getLayoutInflater();
        @SuppressLint("InflateParams") View v = i.inflate(R.layout.dialog_obj, null);
        editX = (EditText) v.findViewById(R.id.obj_x);
        editY = (EditText) v.findViewById(R.id.obj_y);
        editZ = (EditText) v.findViewById(R.id.obj_z);
        editRot_X = (EditText) v.findViewById(R.id.rot_obj_x);
        editRot_Y = (EditText) v.findViewById(R.id.rot_obj_y);
        editRot_Z = (EditText) v.findViewById(R.id.rot_obj_z);
        editR = (EditText) v.findViewById(R.id.obj_r);
        editG = (EditText) v.findViewById(R.id.obj_g);
        editB = (EditText) v.findViewById(R.id.obj_b);
        angle = (EditText) v.findViewById(R.id.angle);
        rayon = (EditText) v.findViewById(R.id.rayon);
        effect = (EditText) v.findViewById(R.id.effect);
        shine = (EditText) v.findViewById(R.id.shine);
        editR.setOnFocusChangeListener(color_handler);
        editG.setOnFocusChangeListener(color_handler);
        editB.setOnFocusChangeListener(color_handler);
        Spinner_obj = (Spinner) v.findViewById(R.id.spinner_obj);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(getActivity(),
                R.array.objects, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        Spinner_obj.setAdapter(adapter);
        Spinner_obj.setOnItemSelectedListener(new OnSpinnerItemClickedObj());
        Spinner_noise = (Spinner) v.findViewById(R.id.spinner_noise);
        ArrayAdapter<CharSequence> adapter_noise = ArrayAdapter.createFromResource(getActivity(),
                R.array.noise, android.R.layout.simple_spinner_item);
        adapter_noise.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        Spinner_noise.setAdapter(adapter_noise);
        if (exist) {
            editX.setText(String.valueOf(existing.getX()));
            editY.setText(String.valueOf(existing.getY()));
            editZ.setText(String.valueOf(existing.getZ()));
            editRot_X.setText(String.valueOf(existing.getRotx()));
            editRot_Y.setText(String.valueOf(existing.getRoty()));
            editRot_Z.setText(String.valueOf(existing.getRotz()));
            editR.setText(String.valueOf(existing.getR()));
            editG.setText(String.valueOf(existing.getG()));
            editB.setText(String.valueOf(existing.getB()));
            angle.setText(String.valueOf(existing.getAngle()));
            rayon.setText(String.valueOf(existing.getRayon()));
            effect.setText(String.valueOf(existing.getEffect()));
            shine.setText(String.valueOf(existing.getShine()));
            Spinner_obj.setSelection(existing.getType(true) - 1);
            Spinner_noise.setSelection(existing.getTexture());
        }

        dial.setView(v);
        return dial.create();
    }

    private void handle_send() {
        if (editX.getText().toString().isEmpty()
                || editY.getText().toString().isEmpty()
                || editZ.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Position Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (editRot_X.getText().toString().isEmpty()
                || editRot_Y.getText().toString().isEmpty()
                || editRot_Z.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Rotation Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (editR.getText().toString().isEmpty()
                || editG.getText().toString().isEmpty()
                || editB.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Color Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (angle.isEnabled() && angle.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Angle Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (rayon.isEnabled() && rayon.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Rayon Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (effect.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Effect Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (shine.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Shine Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (!angle.isEnabled())
            angle.setText("0");
        if (!rayon.isEnabled())
            rayon.setText("0");
        String send = "OBJ;"
                + Integer.toString(Spinner_obj.getSelectedItemPosition() + 1) + sep
                + editX.getText().toString() + sep
                + editY.getText().toString() + sep
                + editZ.getText().toString() + sep
                + editRot_X.getText().toString() + sep
                + editRot_Y.getText().toString() + sep
                + editRot_Z.getText().toString() + sep
                + editB.getText().toString() + sep
                + editG.getText().toString() + sep
                + editR.getText().toString() + sep
                + angle.getText().toString() + sep
                + rayon.getText().toString() + sep
                + shine.getText().toString() + sep
                + effect.getText().toString() + sep
                + Integer.toString(Spinner_noise.getSelectedItemPosition()) + "*";
        ConnectService.send_data(send);
    }

    private void set_obj() {
        if (editX.getText().toString().isEmpty()
                || editY.getText().toString().isEmpty()
                || editZ.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Position Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (editRot_X.getText().toString().isEmpty()
                || editRot_Y.getText().toString().isEmpty()
                || editRot_Z.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Rotation Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (editR.getText().toString().isEmpty()
                || editG.getText().toString().isEmpty()
                || editB.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Color Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (angle.isEnabled() && angle.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Angle Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (rayon.isEnabled() && rayon.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Rayon Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (effect.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Effect Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (shine.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Shine Value", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (!angle.isEnabled())
            angle.setText("0");
        if (!rayon.isEnabled())
            rayon.setText("0");
        existing.setX(Float.parseFloat(editX.getText().toString()));
        existing.setY(Float.parseFloat(editY.getText().toString()));
        existing.setZ(Float.parseFloat(editZ.getText().toString()));
        existing.setRotx(Float.parseFloat(editRot_X.getText().toString()));
        existing.setRoty(Float.parseFloat(editRot_Y.getText().toString()));
        existing.setRotz(Float.parseFloat(editRot_Z.getText().toString()));
        existing.setR(Integer.parseInt(editB.getText().toString()));
        existing.setG(Integer.parseInt(editG.getText().toString()));
        existing.setB(Integer.parseInt(editR.getText().toString()));
        existing.setAngle(Float.parseFloat(angle.getText().toString()));
        existing.setRayon(Float.parseFloat(rayon.getText().toString()));
        existing.setEffect(Float.parseFloat(effect.getText().toString()));
        existing.setShine(Float.parseFloat(shine.getText().toString()));
        existing.setTexture(Spinner_noise.getSelectedItemPosition());
        existing.setType(Spinner_obj.getSelectedItemPosition() + 1);
        ChObjDialog.objectAdapter.notifyDataSetChanged();
    }

    private final View.OnFocusChangeListener color_handler = new View.OnFocusChangeListener() {
        @Override
        public void onFocusChange(View v, boolean hasFocus) {
            if (hasFocus) {
                FragmentManager fm = getFragmentManager();
                ColorDialog pick = ColorDialog.newInstance(true);
                pick.show(fm, "color_fragment");
                editR.clearFocus();
                editG.clearFocus();
                editB.clearFocus();
            }
        }
    };


}
