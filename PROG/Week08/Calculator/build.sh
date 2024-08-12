rm -rf bin
mkdir -f bin
javac -sourcepath ../../.. -d bin CalculatorController.java Calculator.java
cp calculator.fxml bin/PROG/Week08/Calculator/
jar cfe Calculator.jar PROG.Week08.Calculator.CalculatorController -C bin/ .
mv Calculator.jar bin/
