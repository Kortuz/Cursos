package city;

import visitor.CountingVehicle;
import visitor.VehicleByDate;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class City {
    private List<Comuna> comunas = new ArrayList<Comuna>();

    /**
     * adds a comuna
     * @param comuna
     *      comuna added
     */
    public void add(Comuna comuna) {
        comunas.add(comuna);
    }

    /**
     * returns the list of comunas
     * @return
     *      list of comuna of the city
     */
    public List<Comuna> comunas() {
        return comunas;
    }

    /**
     * counts the vehicles that are at the city
     * @return
     *      the quantity
     */
    public int countingVehicle() {
        int result = 0;
        for (Comuna comuna: comunas)
            result += comuna.countingVehicle();
        return result;
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
        for (Comuna comuna : comunas)
            comuna.accept(v);
        return v.getResult();
    }
}