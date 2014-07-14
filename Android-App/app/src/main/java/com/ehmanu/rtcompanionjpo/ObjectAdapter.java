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

public class ObjectAdapter extends ArrayAdapter<Object> {
    private final ArrayList<Object> obj_list;

    public ObjectAdapter(Context context, ArrayList<Object> objects) {
        super(context, R.layout.obj_list, objects);
        this.obj_list = objects;
    }

    @SuppressLint("InflateParams")
    public View getView(int position, View convertView, ViewGroup parent) {
        View v = convertView;
        if (v == null) {
            LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            v = inflater.inflate(R.layout.obj_list, null);
        }
        Object obj = obj_list.get(position);
        if (obj != null) {
            SurfaceView surface = (SurfaceView) v.findViewById(R.id.colorView);
            surface.setBackgroundColor(Color.rgb(obj.getB(), obj.getG(), obj.getR()));
            TextView show_x = (TextView) v.findViewById(R.id.show_x);
            TextView show_y = (TextView) v.findViewById(R.id.show_y);
            TextView show_z = (TextView) v.findViewById(R.id.show_z);
            TextView ttd = (TextView) v.findViewById(R.id.toptextdata);
            if (ttd != null)
                ttd.setText(obj.getType());
            if (show_x != null)
                show_x.setText("X : " + String.valueOf(obj.getX()));
            if (show_y != null)
                show_y.setText("Y : " + String.valueOf(obj.getY()));
            if (show_z != null)
                show_z.setText("Z : " + String.valueOf(obj.getZ()));
        }
        return v;
    }
}
