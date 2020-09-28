package visitor;

import city.*;

import java.util.HashSet;


public class VehicleByDate extends Visitor{

    private final int year;
    private HashSet<Vehicle> result = new HashSet<>();

    /**
     * constructor of the operation
     * @param year
     *      the year of the vehicles we will find
     */
    public VehicleByDate(int year){
        this.year = year;
    }


    /**
     * method to visit autos
     * @param auto
     *      visited auto
     */
    public void visitAuto(Auto auto) {
        processVehicle(auto);
    }

    /**
     * method for avoid duplicated code in adding vehicles
     * @param vehicle
     *      the vehicle to add
     */
    private void processVehicle(Vehicle vehicle) {
        if(vehicle.getYear() == this.year)
            result.add(vehicle);
    }

    /**
     * method to visit trucks
     * @param truck
     *      visited truck
     */
    public void visitTruck(Truck truck) {
        processVehicle(truck);
    }

    /**
     * return the vehicles
     * @return
     *   result of the search
     */
    public HashSet<Vehicle> getResult() {
        return result;
    }
}
