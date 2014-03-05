#include <iostream>
#include "rk4_index.h"
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    RK4CircSim capacitorVoltage;
    cout << "Welcome to a Classical Fourth-Order Runge-Kutta Circuit Simulation Solution!" << endl;
    cout << "Enter your name O:)" << endl;
    //cin >> userName;
    cout << "Just kidding, we don't need your name. Nobody needs your name gosh." << endl;
    capacitorVoltage.setParameters();
    capacitorVoltage.setStepSize();


}
