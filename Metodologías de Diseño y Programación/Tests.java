import city.*;
import org.junit.*;
import visitor.CountingVehicle;
import visitor.VehicleByDate;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class Tests {
    City city;
    Comuna comuna1;
    Comuna comuna2;
    Vehicle auto1;
    Vehicle truck1;
    Vehicle auto2;
    Vehicle truck2;

    @Before
    public void setUp(){
        city = new City();
        comuna1 = new Comuna();
        comuna2 = new Comuna();
        auto1 = new Auto(2000);
        auto2 = new Auto(2010);
        truck1 = new Truck(1980);
        truck2 = new Truck(2000);

    }

    @Test
    public void constructorTest(){
        assertEquals(2000, auto1.getYear());
        assertEquals(1980, truck1.getYear());
        city.add(comuna1);
        assertEquals(comuna1, city.comunas().get(0));

    }

    @Test
    public void countingVehicleTest(){
        assertEquals(0, comuna1.countingVehicle());
        assertEquals(0, city.countingVehicle());

        comuna1.add(auto1);
        comuna1.add(auto2);

        comuna2.add(truck1);

        city.add(comuna1);
        city.add(comuna2);

        assertEquals(3, city.countingVehicle());
        assertEquals(2, comuna1.countingVehicle());

        CountingVehicle counting = new CountingVehicle();
        Auto testOperation = new Auto(1);
        counting.visitAuto(testOperation);
        assertEquals(1, counting.numberOfAutos());
        assertEquals(0, counting.numberOfTrucks());


    }

    @Test
    public void vehicleByDate(){
        assertEquals(0, comuna1.vehicleByDate(2000).size());
        assertEquals(0, city.vehicleByDate(2000).size());
        comuna1.add(auto1);
        comuna1.add(auto2);

        comuna2.add(truck1);

        city.add(comuna1);
        city.add(comuna2);

        assertEquals(1, city.vehicleByDate(2010).size());
        comuna1.add(truck2);
        assertEquals(2, comuna1.vehicleByDate(2000).size());

        assertTrue(comuna1.vehicleByDate(2000).contains(truck2));
    }
}
