package com.ehmanu.rtcompanionjpo;

import android.view.View;
import android.widget.AdapterView;

/**
 ** Created by chambo_e on 7/3/14.
 **/
class OnSpinnerItemClickedObj implements AdapterView.OnItemSelectedListener {
    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {
        String choice = parent.getItemAtPosition(pos).toString();
        if (choice.equals("Plan")) {
            AddObj.angle.setEnabled(false);
            AddObj.rayon.setEnabled(false);
            AddObj.angle.setHint("Angle");
            AddObj.rayon.setHint("Rayon");
        } else if (choice.equals("Sphere")) {
            AddObj.angle.setEnabled(false);
            AddObj.rayon.setEnabled(true);
            AddObj.angle.setHint("Angle");
            AddObj.rayon.setHint("Rayon");
        } else if (choice.equals("Cylindre")) {
            AddObj.angle.setEnabled(false);
            AddObj.rayon.setEnabled(true);
            AddObj.angle.setHint("Angle");
            AddObj.rayon.setHint("Rayon");
        } else if (choice.equals("Cone")) {
            AddObj.angle.setEnabled(true);
            AddObj.rayon.setEnabled(true);
            AddObj.angle.setHint("Angle");
            AddObj.rayon.setHint("Rayon");
        } else if (choice.equals("Tore")) {
            AddObj.angle.setEnabled(true);
            AddObj.rayon.setEnabled(true);
            AddObj.angle.setHint("Low R");
            AddObj.rayon.setHint("High R");
        } else if (choice.equals("Cube Troué")) {
            AddObj.angle.setEnabled(true);
            AddObj.rayon.setEnabled(true);
            AddObj.angle.setHint("Low R");
            AddObj.rayon.setHint("High R");
        }
    }

    @Override
    public void onNothingSelected(AdapterView parent) {
    }
}