package city;

import visitor.Visitor;

public class Auto extends Vehicle {

    /**
     * constructor for autos
     * @param y
     *      the year of the auto
     */
    public Auto(int y) {
        year = y;
    }

    /**
     * method to accept a visitor
     * @param visitor
     *      the visitor that visits this auto
     */
    @Override
    public void accept(Visitor visitor) {
        visitor.visitAuto(this);
    }
}