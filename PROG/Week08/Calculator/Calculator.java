package PROG.Week08.Calculator;

import javafx.beans.property.*;

public class Calculator {
    public enum Operations {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE
    };

    private ObjectProperty<Operations> operation = new SimpleObjectProperty<Operations>();
    private ObjectProperty<Double> firstNumber = new SimpleObjectProperty<Double>();
    private ObjectProperty<Double> secondNumber = new SimpleObjectProperty<Double>();

    public Calculator() {
        firstNumber.set(null);
    }

    public final Double getFirstNumber() {
        return firstNumber.get();
    }

    public final void setFirstNumber(double number) {
        firstNumber.set(number);
    }

    public final Double getSecondNumber() {
        return secondNumber.get();
    }

    public final void setSecondNumber(double number) {
        secondNumber.set(number);
    }

    public final Operations getOperation() {
        return operation.get();
    }

    public final void setOperation(Operations operation) {
        this.operation.set(operation);
    }

    public ObjectProperty<Double> firstNumberProperty() {
        return firstNumber;
    }

    public ObjectProperty<Double> secondNumberProperty() {
        return secondNumber;
    }

    public ObjectProperty<Operations> operationProperty() {
        return operation;
    }

    public double getResult() throws Exception {
        if (firstNumber == null)
            throw new Exception("First number not set.");
        if (secondNumber == null)
            throw new Exception("Second number not set.");
        if (operation == null)
            throw new Exception("Operation not set.");

        switch (operation.get()) {
            default:
                // shouldn't happen but compiler is complaining
            case ADD:
                return firstNumber.get() + secondNumber.get();
            case SUBTRACT:
                return firstNumber.get() - secondNumber.get();
            case MULTIPLY:
                return firstNumber.get() * secondNumber.get();
            case DIVIDE:
                return firstNumber.get() / secondNumber.get();
        }
    }
}
