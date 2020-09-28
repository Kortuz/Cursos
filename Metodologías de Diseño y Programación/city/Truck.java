package city;

import visitor.Visitor;

public class Truck extends Vehicle {

    /**
     * constructor for trucks
     * @param y
     *      the year of the truck
     */
    public Truck(int y) {
        year = y;
    }

    /**
     * method to accept a visitor
     * @param visitor
     *      the visitor that visits this auto
     */
    @Override
    public void accept(Visitor visitor) {
        visitor.visitTruck(this);
    }
}