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
 * * Created by chambo_e on 7/11/14.
 */
public class ChSpotDialog extends DialogFragment {

    public static ArrayList<Spot> spots;

    private ChSpotDialog(ArrayList<Spot> spot) {
        spots = spot;
    }

    public static SpotAdapter spotAdapter;

    public static ChSpotDialog newInstance(ArrayList<Spot> spot) {
        return new ChSpotDialog(spot);
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        @SuppressLint("InflateParams") View v = getActivity().getLayoutInflater().inflate(R.layout.change_obj_dialog, null);
        ListView listView = (ListView) v.findViewById(R.id.list);
        spotAdapter = new SpotAdapter(getActivity().getApplicationContext(), spots);
        listView.setAdapter(spotAdapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                FragmentManager fm = getFragmentManager();
                AddSpot addSpot = AddSpot.newInstance(spots.get(position), spots.indexOf(spots.get(position)));
                addSpot.show(fm, "add_obj_fragment");
            }
        });
        AlertDialog.Builder dial = new AlertDialog.Builder(getActivity())
                .setTitle("Object List")
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                String result = "";
                                for (Spot tmp : spots) {
                                    result += send_spots(tmp);
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

    private String send_spots(Spot spot) {

        return "SP;" + 
        spot.getX() + AddObj.sep +
                spot.getY() + AddObj.sep +
                spot.getZ() + AddObj.sep +
                spot.getR() + AddObj.sep +
                spot.getG() + AddObj.sep +
                spot.getB() + AddObj.sep;
    }
}
