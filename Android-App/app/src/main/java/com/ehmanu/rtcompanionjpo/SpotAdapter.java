package com.ehmanu.rtcompanionjpo;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.SurfaceView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * * Created by chambo_e on 7/11/14.
 */
public class SpotAdapter extends ArrayAdapter<Spot> {

    private final ArrayList<Spot> spot_list;

    public SpotAdapter(Context context, ArrayList<Spot> spots) {
        super(context, R.layout.obj_list, spots);
        this.spot_list = spots;
    }

    @SuppressLint("InflateParams")
    public View getView(int position, View convertView, ViewGroup parent) {
        View v = convertView;
        if (v == null) {
            LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            v = inflater.inflate(R.layout.obj_list, null);
        }
        Spot spot = spot_list.get(position);
        if (spot != null) {
            SurfaceView surface = (SurfaceView) v.findViewById(R.id.colorView);
            surface.setBackgroundColor(Color.rgb(spot.getB(), spot.getG(), spot.getR()));
            TextView show_x = (TextView) v.findViewById(R.id.show_x);
            TextView show_y = (TextView) v.findViewById(R.id.show_y);
            TextView show_z = (TextView) v.findViewById(R.id.show_z);
            TextView ttd = (TextView) v.findViewById(R.id.toptextdata);
            if (ttd != null)
                ttd.setText("Spot : ");
            if (show_x != null)
                show_x.setText("X : " + String.valueOf(spot.getX()));
            if (show_y != null)
                show_y.setText("Y : " + String.valueOf(spot.getY()));
            if (show_z != null)
                show_z.setText("Z : " + String.valueOf(spot.getZ()));
        }
        return v;
    }
}