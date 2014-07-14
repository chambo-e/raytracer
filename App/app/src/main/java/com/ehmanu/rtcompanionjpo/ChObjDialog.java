package com.ehmanu.rtcompanionjpo;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.FragmentManager;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import java.util.ArrayList;

/**
 ** Created by chambo_e on 7/10/14.
 **/
public class ChObjDialog extends DialogFragment {

    public static ArrayList<Object> objects;

    private ChObjDialog(ArrayList<Object> obj) {
        this.objects = obj;
    }
    public static ObjectAdapter objectAdapter;

    public static ChObjDialog newInstance(ArrayList<Object> objects) {
        return new ChObjDialog(objects);
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        @SuppressLint("InflateParams") View v = getActivity().getLayoutInflater().inflate(R.layout.change_obj_dialog, null);
        ListView listView = (ListView) v.findViewById(R.id.list);
        objectAdapter = new ObjectAdapter(getActivity().getApplicationContext(), objects);
        listView.setAdapter(objectAdapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                FragmentManager fm = getFragmentManager();
                AddObj addObj = AddObj.newInstance(objects.get(position), objects.indexOf(objects.get(position)), "Change Object");
                addObj.show(fm, "add_obj_fragment");
            }
        });
        AlertDialog.Builder dial = new AlertDialog.Builder(getActivity())
                .setTitle("Object List")
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                String result = "";
                                for (Object tmp : objects) {
                                    result += send_obj(tmp);
                                }
                                result += "*";
                                ConnectService.send_data(result);
                            }
                        }
                )
                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {

                            }
                        }
                );
        dial.setView(v);
        return dial.create();
    }

    private String send_obj(Object obj) {

        return "OB;"
                + Integer.toString(obj.getType(true)) + AddObj.sep
                + Float.toString(obj.getX()) + AddObj.sep
                + Float.toString(obj.getY()) + AddObj.sep
                + Float.toString(obj.getZ()) + AddObj.sep
                + Float.toString(obj.getRotx()) + AddObj.sep
                + Float.toString(obj.getRotx()) + AddObj.sep
                + Float.toString(obj.getRotx()) + AddObj.sep
                + Integer.toString(obj.getR()) + AddObj.sep
                + Integer.toString(obj.getG()) + AddObj.sep
                + Integer.toString(obj.getB()) + AddObj.sep
                + Float.toString(obj.getAngle()) + AddObj.sep
                + Float.toString(obj.getRayon()) + AddObj.sep
                + Float.toString(obj.getShine()) + AddObj.sep
                + Float.toString(obj.getEffect()) + AddObj.sep
                + Integer.toString(obj.getTexture()) + AddObj.sep;
    }
}
