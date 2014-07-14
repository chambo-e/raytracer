package com.ehmanu.rtcompanionjpo;

/**
 * * Created by chambo_e on 7/9/14.
 */
public class Object {
    private float y, x, z, rotx, roty, rotz, angle_obj, rayon_obj, effect_obj, shine_obj;
    private int r;
    private int g;
    private int b;
    private int type;
    private int texture;

    public Object() {
        y = 0;
        x = 0;
        z = 0;
        rotx = 0;
        r = 0;
        g = 0;
        b = 0;
        roty = 0;
        rotz = 0;
        angle_obj = 0;
        rayon_obj = 0;
        shine_obj = 0;
        effect_obj = 0;
        type = 0;
        texture = 0;
    }

    public String getType() {
        if (this.type == 1)
            return ("Plan");
        else if (this.type == 2)
            return ("Sphere");
        else if (this.type == 3)
            return ("Cone");
        else if (this.type == 4)
            return ("Cylindre");
        else if (this.type == 5)
            return ("Tore");
        else if (this.type == 6)
            return ("Cube Troué");
        return (null);
    }

    @SuppressWarnings("all")
    public int getType(boolean is) {
        return (this.type);
    }

    public float getX() {
        return this.x;
    }

    public float getY() {
        return this.y;
    }

    public float getZ() {
        return this.z;
    }

    public int getR() {
        return this.r;
    }

    public int getG() {
        return this.g;
    }

    public int getB() {
        return this.b;
    }

    public float getRotx() {
        return this.rotx;
    }

    public float getRoty() {
        return this.roty;
    }

    public float getRotz() {
        return this.rotz;
    }

    public float getAngle() {
        return this.angle_obj;
    }

    public float getEffect() {
        return this.effect_obj;
    }

    public float getRayon() {
        return this.rayon_obj;
    }

    public float getShine() {
        return this.shine_obj;
    }

    public int getTexture() {
        return this.texture;
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

    public void setRotx(float rotx) {
        this.rotx = rotx;
    }

    public void setRoty(float roty) {
        this.roty = roty;
    }

    public void setRotz(float rotz) {
        this.rotz = rotz;
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

    public void setAngle(float angle_obj) {
        this.angle_obj = angle_obj;
    }

    public void setEffect(float effect_obj) {
        this.effect_obj = effect_obj;
    }

    public void setRayon(float rayon_obj) {
        this.rayon_obj = rayon_obj;
    }

    public void setShine(float shine_obj) {
        this.shine_obj = shine_obj;
    }

    public void setTexture(int texture) {
        this.texture = texture;
    }

    public void setType(int type) {
        this.type = type;
    }
}

