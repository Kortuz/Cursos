package city;

import visitor.Visitor;

public abstract class Vehicle {
    protected int year;
    public int getYear() {
        return year;
    }
    public abstract void accept(Visitor visitor);
}