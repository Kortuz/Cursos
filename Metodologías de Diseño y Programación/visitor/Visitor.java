package visitor;

import city.*;

public class Visitor {

    /**
     * method to visit autos
     * @param auto
     *      visited auto
     */
    public void visitAuto(Auto auto){
    }

    /**
     * method to visit trucks
     * @param truck
     *      visited truck
     */
    public void visitTruck(Truck truck){
    }

    /**
     * method for the visitors to visit a comuna
     * @param comuna
     *      comuna where the visitor will visit their vehicles
     */
    public void visitComuna(Comuna comuna){
        for (Vehicle vehicle : comuna.vehicles())
            vehicle.accept(this);
    }
}
