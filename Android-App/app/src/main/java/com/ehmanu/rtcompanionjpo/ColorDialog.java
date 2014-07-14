package com.ehmanu.rtcompanionjpo;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;

/**
 ** Created by chambo_e on 7/4/14.
 **/
 public class ColorDialog extends android.app.DialogFragment {

    private ColorPicker picker;
    private int b = 0;

    private ColorDialog() {
    }

    public static ColorDialog newInstance(boolean which) {
        ColorDialog frag = new ColorDialog();
        Bundle calling = new Bundle();
        calling.putBoolean("calling", which);
        frag.setArguments(calling);
        return frag;
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        AlertDialog.Builder dial = new AlertDialog.Builder(getActivity())
                .setTitle("Pick a color")
                .setPositiveButton("OK",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                            }
                        }
                )
                .setNegativeButton("Cancel",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                picker.setOldCenterColor(picker.getColor());
                                if (getArguments().getBoolean("calling")) {
                                    AddObj.editR.setText("");
                                    AddObj.editG.setText("");
                                    AddObj.editB.setText("");
                                    dialog.dismiss();
                                } else {
                                    AddSpot.editR.setText("");
                                    AddSpot.editG.setText("");
                                    AddSpot.editB.setText("");
                                    dialog.dismiss();
                                }
                            }
                        }
                );
        LayoutInflater i = getActivity().getLayoutInflater();
        @SuppressLint("InflateParams") View v = i.inflate(R.layout.dialog_color, null);
        picker = (ColorPicker) v.findViewById(R.id.picker);
        SVBar svBar = (SVBar) v.findViewById(R.id.svbar);
        picker.addSVBar(svBar);
        picker.setShowOldCenterColor(false);
        int r;
        int g;
        if (getArguments().getBoolean("calling")) {
            if (!AddObj.editR.getText().toString().isEmpty())
                r = Integer.parseInt(AddObj.editR.getText().toString());
            else
                r = 128;
            if (!AddObj.editG.getText().toString().isEmpty())
                g = Integer.parseInt(AddObj.editG.getText().toString());
            else
                g = 255;
            if (!AddObj.editB.getText().toString().isEmpty())
                b = Integer.parseInt(AddObj.editB.getText().toString());
            picker.setColor(Color.rgb(r, g, b));
        } else {
            if (!AddSpot.editR.getText().toString().isEmpty())
                r = Integer.parseInt(AddSpot.editR.getText().toString());
            else
                r = 128;
            if (!AddSpot.editG.getText().toString().isEmpty())
                g = Integer.parseInt(AddSpot.editG.getText().toString());
            else
                g = 255;
            if (!AddSpot.editB.getText().toString().isEmpty())
                b = Integer.parseInt(AddSpot.editB.getText().toString());
            picker.setColor(Color.rgb(r, g, b));
        }
        picker.setOnColorChangedListener(new ColorPicker.OnColorChangedListener() {
            @Override
            public void onColorChanged(int color) {
                if (getArguments().getBoolean("calling")) {
                    AddObj.editR.setText(String.valueOf(Color.red(color)));
                    AddObj.editG.setText(String.valueOf(Color.green(color)));
                    AddObj.editB.setText(String.valueOf(Color.blue(color)));
                } else {
                    AddSpot.editR.setText(String.valueOf(Color.red(color)));
                    AddSpot.editG.setText(String.valueOf(Color.green(color)));
                    AddSpot.editB.setText(String.valueOf(Color.blue(color)));
                }
            }
        });
        dial.setView(v);
        return dial.create();
    }
}