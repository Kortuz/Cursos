package visitor;

import city.Auto;
import city.Truck;

public class CountingVehicle extends Visitor {

    private int autos = 0;
    private int trucks = 0;

    /**
     * @return
     *      the number of vehicles counted
     */
    public int getResult() {
        return autos + trucks;
    }

    /**
     * method to visit trucks
     * @param truck
     *      visited truck
     */
    @Override
    public void visitTruck(Truck truck) {
        trucks++;
    }

    /**
     * method to visit autos
     * @param auto
     *      visited auto
     */
    @Override
    public void visitAuto(Auto auto) {
        autos++;
    }

    public int numberOfTrucks() {
        return trucks;
    }

    public int numberOfAutos() {
        return autos;
    }
}
