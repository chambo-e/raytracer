package com.ehmanu.rtcompanionjpo;

import android.app.Fragment;
import android.app.FragmentManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import java.util.ArrayList;

public class MainControlFragment extends Fragment {

    private Button aa;
    private ArrayList<Object> obj_list;
    private ArrayList<Spot> spot_list;

    public MainControlFragment() {
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        final String[] aa_state = new String[1];
        View v = inflater.inflate(R.layout.fragment_main_control, container, false);
        Button obj = (Button) v.findViewById(R.id.add_obj);
        Button spot = (Button) v.findViewById(R.id.add_spot);
        final Button ch_obj = (Button) v.findViewById(R.id.ch_obj);
        Button ch_spot = (Button) v.findViewById(R.id.ch_spot);
        aa = (Button) v.findViewById(R.id.aa);
        Button connected = (Button) v.findViewById(R.id.connected);
        connected.setText(getResources().getString(R.string.conn) + "\n\n" + ConnectService.get_name_server());
        ConnectService connectService = new ConnectService();
        if (connectService.ask_aa())
            aa_state[0] = "On";
        else
            aa_state[0] = "Off";
        aa.setText(getResources().getString(R.string.aa) + "\n\n" + aa_state[0]);
        aa.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (aa_state[0].equals("On")) {
                    aa_state[0] = "Off";
                    ConnectService.send_data("AA;0*");
                    aa.setText(getResources().getString(R.string.aa) + "\n\n" + aa_state[0]);
                } else {
                    aa_state[0] = "On";
                    ConnectService.send_data("AA;1*");
                    aa.setText(getResources().getString(R.string.aa) + "\n\n" + aa_state[0]);
                }
            }
        });
        obj.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FragmentManager fm = getFragmentManager();
                AddObj addObj = AddObj.newInstance("Add Object");
                addObj.show(fm, "add_obj_fragment");
            }
        });
        spot.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                FragmentManager fm = getFragmentManager();
                AddSpot addSpot = AddSpot.newInstance("Add Spot");
                addSpot.show(fm, "add_obj_fragment");
            }
        });
        ch_obj.setOnClickListener(new View.OnClickListener() {
                                      @Override
                                      public void onClick(View v) {
                                          getActivity().setProgressBarIndeterminateVisibility(true);
                                          ConnectService connectService = new ConnectService();
                                          String result = connectService.ask_obj();
                                          obj_list = new ArrayList<Object>();
                                          new ParseObj() {
                                              @Override
                                              protected void onPostExecute(Boolean is) {
                                                  getActivity().setProgressBarIndeterminateVisibility(false);
                                              }
                                          }.execute(result);
                                          FragmentManager fm = getFragmentManager();
                                          ChObjDialog chObjDialog = ChObjDialog.newInstance(obj_list);
                                          chObjDialog.show(fm, "ch_obj_fragment");
                                      }
                                  }
        );
        ch_spot.setOnClickListener(new View.OnClickListener() {
                                      @Override
                                      public void onClick(View v) {
                                          getActivity().setProgressBarIndeterminateVisibility(true);
                                          ConnectService connectService = new ConnectService();
                                          String result = connectService.ask_spot();
                                          spot_list = new ArrayList<Spot>();
                                          new ParseSpot() {
                                              @Override
                                              protected void onPostExecute(Boolean is) {
                                                  getActivity().setProgressBarIndeterminateVisibility(false);
                                              }
                                          }.execute(result);
                                          FragmentManager fm = getFragmentManager();
                                          ChSpotDialog chSpotDialog = ChSpotDialog.newInstance(spot_list);
                                          chSpotDialog.show(fm, "ch_spot_fragment");
                                      }
                                  }
        );
        return v;
    }

    private class ParseObj extends AsyncTask<String, Void, Boolean> {

        @Override
        protected Boolean doInBackground(String... params) {
            String[] objects = params[0].split("\\*");
            for (String item : objects) {
                item = item.replace("*", "");
                String[] values = item.split(";");
                Object obj = new Object();
                for (int i = 1; i < values.length; i++) {
                    switch (i) {
                        case 1:
                            obj.setX(Float.parseFloat(values[i]));
                            break;
                        case 2:
                            obj.setY(Float.parseFloat(values[i]));
                            break;
                        case 3:
                            obj.setZ(Float.parseFloat(values[i]));
                            break;
                        case 4:
                            obj.setRotx(Float.parseFloat(values[i]));
                            break;
                        case 5:
                            obj.setRoty(Float.parseFloat(values[i]));
                            break;
                        case 6:
                            obj.setRotz(Float.parseFloat(values[i]));
                            break;
                        case 7:
                            obj.setType(Integer.parseInt(values[i]));
                            break;
                        case 8:
                            obj.setEffect(Float.parseFloat(values[i]));
                            break;
                        case 9:
                            obj.setRayon(Float.parseFloat(values[i]));
                            break;
                        case 10:
                            obj.setAngle(Float.parseFloat(values[i]));
                            break;
                        case 11:
                            obj.setR(Integer.parseInt(values[i]));
                            break;
                        case 12:
                            obj.setG(Integer.parseInt(values[i]));
                            break;
                        case 13:
                            obj.setB(Integer.parseInt(values[i]));
                            break;
                        case 15:
                            obj.setShine(Float.parseFloat(values[i]));
                            break;
                        case 16:
                            obj.setTexture(Integer.parseInt(values[i]));
                            break;
                    }
                }
                obj_list.add(obj);
                if (ChObjDialog.objectAdapter != null) {
                    ChObjDialog.objectAdapter.notifyDataSetChanged();
                }
            }
            return true;
        }
    }


    private class ParseSpot extends AsyncTask<String, Void, Boolean> {

        @Override
        protected Boolean doInBackground(String... params) {
            String[] spots = params[0].split("\\*");
            for (String item : spots) {
                item = item.replace("*", "");
                String[] values = item.split(";");
                Spot spot = new Spot();
                for (int i = 1; i < values.length; i++) {
                    switch (i) {
                        case 1:
                            spot.setX(Float.parseFloat(values[i]));
                            break;
                        case 2:
                            spot.setY(Float.parseFloat(values[i]));
                            break;
                        case 3:
                            spot.setZ(Float.parseFloat(values[i]));
                            break;
                        case 5:
                            spot.setR(Integer.parseInt(values[i]));
                            break;
                        case 6:
                            spot.setG(Integer.parseInt(values[i]));
                            break;
                        case 7:
                            spot.setB(Integer.parseInt(values[i]));
                            break;
                    }
                }
                spot_list.add(spot);
                if (ChSpotDialog.spotAdapter != null) {
                    ChSpotDialog.spotAdapter.notifyDataSetChanged();
                }
            }
            return true;
        }
    }
}
