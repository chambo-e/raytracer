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
import android.widget.EditText;
import android.widget.Toast;

/**
 ** Created by chambo_e on 7/5/14.
 **/
 public class AddSpot extends DialogFragment {

    public static EditText editR, editG, editB;
    private EditText editX, editY, editZ;
    private String title;
    private Spot existing;
    private boolean exist = false;
    private int pos;

    private AddSpot(String title) {
        this.title = title;
    }

    private AddSpot(Spot spot, int pos, String title) {
        this.title = title;
        this.existing = spot;
        this.exist = true;
        this.pos = pos;
    }

    public static AddSpot newInstance(String title) {
        return new AddSpot(title);
    }

    public static AddSpot newInstance(Spot spot, int pos, String title) {
        return new AddSpot(spot, pos, title);
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        AlertDialog.Builder dial = new AlertDialog.Builder(getActivity())
                .setTitle(title)
                .setPositiveButton("OK",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                if (exist)
                                    set_spot();
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
                    ChSpotDialog.spots.remove(pos);
                    ChSpotDialog.spotAdapter.notifyDataSetChanged();
                    dismiss();
                }
            });
        LayoutInflater i = getActivity().getLayoutInflater();
        @SuppressLint("InflateParams") View v = i.inflate(R.layout.dialog_spot, null);
        editX = (EditText) v.findViewById(R.id.spot_x);
        editY = (EditText) v.findViewById(R.id.spot_y);
        editZ = (EditText) v.findViewById(R.id.spot_z);
        editR = (EditText) v.findViewById(R.id.spot_r);
        editG = (EditText) v.findViewById(R.id.spot_g);
        editB = (EditText) v.findViewById(R.id.spot_b);
        editR.setOnFocusChangeListener(color_handler);
        editG.setOnFocusChangeListener(color_handler);
        editB.setOnFocusChangeListener(color_handler);
        if (exist) {
            editX.setText(String.valueOf(existing.getX()));
            editY.setText(String.valueOf(existing.getY()));
            editZ.setText(String.valueOf(existing.getZ()));
            editR.setText(String.valueOf(existing.getR()));
            editG.setText(String.valueOf(existing.getG()));
            editB.setText(String.valueOf(existing.getB()));
        }
        dial.setView(v);
        return dial.create();
    }

    private final View.OnFocusChangeListener color_handler = new View.OnFocusChangeListener() {
        @Override
        public void onFocusChange(View v, boolean hasFocus) {
            if (hasFocus) {
                FragmentManager fm = getFragmentManager();
                ColorDialog pick = ColorDialog.newInstance(false);
                pick.show(fm, "color_fragment");
                editR.clearFocus();
                editG.clearFocus();
                editB.clearFocus();
            }
        }
    };

    private void handle_send() {
        if (editX.getText().toString().isEmpty()
                || editY.getText().toString().isEmpty()
                || editZ.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Position Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (editR.getText().toString().isEmpty()
                || editG.getText().toString().isEmpty()
                || editB.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Color Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        String send;
        send = "SPOT;" +
                editX.getText().toString() + AddObj.sep +
                editY.getText().toString() + AddObj.sep +
                editZ.getText().toString() + AddObj.sep +
                editR.getText().toString() + AddObj.sep +
                editG.getText().toString() + AddObj.sep +
                editB.getText().toString() + AddObj.sep + "*";
        ConnectService.send_data(send);
    }

    private void set_spot() {
        if (editX.getText().toString().isEmpty()
                || editY.getText().toString().isEmpty()
                || editZ.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Position Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        if (editR.getText().toString().isEmpty()
                || editG.getText().toString().isEmpty()
                || editB.getText().toString().isEmpty()) {
            Toast.makeText(getActivity(), "Invalid Color Values", Toast.LENGTH_SHORT).show();
            return ;
        }
        existing.setX(Float.parseFloat(editX.getText().toString()));
        existing.setY(Float.parseFloat(editY.getText().toString()));
        existing.setZ(Float.parseFloat(editZ.getText().toString()));
        existing.setR(Integer.parseInt(editR.getText().toString()));
        existing.setG(Integer.parseInt(editG.getText().toString()));
        existing.setB(Integer.parseInt(editB.getText().toString()));
    }
}
