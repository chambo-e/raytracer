package com.ehmanu.rtcompanionjpo;

/**
 * * Created by chambo_e on 7/11/14.
 */
public class Spot {
        private float y, x, z;
        private int r;
        private int g;
        private int b;

        public Spot() {
            y = 0;
            x = 0;
            z = 0;
            r = 0;
            g = 0;
            b = 0;
        }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public float getZ() {
        return z;
    }

    public int getR() {
        return r;
    }

    public int getG() {
        return g;
    }

    public int getB() {
        return b;
    }

    public void setX(float x) {
        this.x = x;
    }

    public void setY(float y) {
        this.y = y;
    }

    public void setZ(float z) {
        this.z = z;
    }

    public void setR(int r) {
        this.r = r;
    }

    public void setG(int g) {
        this.g = g;
    }

    public void setB(int b) {
        this.b = b;
    }
}
