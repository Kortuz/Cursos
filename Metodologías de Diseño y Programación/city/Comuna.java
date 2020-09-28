package city;

import visitor.CountingVehicle;
import visitor.VehicleByDate;
import visitor.Visitor;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class Comuna {
    private List<Vehicle> vehicles = new ArrayList<Vehicle>();

    /**
     * adds a vehicle
     * @param v
     *      vehicle added
     */
    public void add(Vehicle v) {
        vehicles.add(v);
    }

    /**
     * returns the list of vehicles
     * @return
     *      list of vehicles of the comuna
     */
    public List<Vehicle> vehicles() {
        return vehicles;
    }
    /**
     * method to accept a visitor
     * @param visitor
     *      the visitor that visits this comuna
     */
    public void accept(Visitor visitor){
        visitor.visitComuna(this);
    }

    /**
     * counts the vehicles that are at the comuna
     * @return
     *      the quantity
     */
    public int countingVehicle(){
        CountingVehicle v = new CountingVehicle();
        this.accept(v);
        return v.getResult();

    }

    /**
     * search for the vehicles of a certain year
     * @param year
     *      the year of the searched vehicles
     * @return
     *      list of vehicles of that year
     */
    public HashSet<Vehicle> vehicleByDate(int year){
        VehicleByDate v = new VehicleByDate(year);
        this.accept(v);
        return v.getResult();
    }
}