#include <iostream>
#include "rk4_index.h"
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>

using namespace std;

const double PI = atan(1.0)*4;

void RK4CircSim::setParameters(){
    cout << "\nWe need the following parameters!\n" << endl;
    cout << "A for Input Voltage Signal Amplitude!" << endl;
    cout << "B for Input Voltage Signal Phase Shift!" << endl;
    cout << "D for Input Voltage Signal DC Offset!" << endl;
    cout << "F for Input Voltage Signal Frequency!" << endl;
    cout << "R for Resistance!" << endl;
    cout << "C for Capacitance!\n" << endl;
    cout << "\nA: "; cin >> paramA;
    cout << "B: "; cin >> paramB;
    cout << "D: "; cin >> paramD;
    cout << "F: "; cin >> paramF;
    cout << "R: "; cin >> paramR;
    cout << "C: "; cin >> paramC;

    twoPiF = 2*PI*paramF;
    twoPiFRC = twoPiF*paramR*paramC;
    denomTwoPiFRC = 1/(1+pow(twoPiFRC,2));
    cosB = cos(paramB);
    sinB = sin(paramB);
    capTimeConst = 1/(paramR*paramC);
}

//double RK4CircSim::twoPiF(double inputFreq){
//    return 2.0*PI*inputFreq;
//}

void RK4CircSim::setStepSize(){
    cout << "\nWe need to set our input step parameter!\nThis shall be computed by multiplying a factor \nto the period of the input signal.\n\nInput a step factor!" << endl;
    cout << "\nStep Factor: "; cin >> stepFactor;
    stepSize = stepFactor*inputPeriod;
}

void RK4CircSim::inputT(){
    data_inputT[0] = 0;
    for(int i = 0; i < 50; i++){
        data_inputT[i+1] = data_inputT[i] + stepSize;
    }
}

void RK4CircSim::outputTrueY(){
    for(int i = 0; i < 50; i++){
        data_trueY[i] = paramB + exp(-1.0*data_inputT[i]*capTimeConst)*((paramA/denomTwoPiFRC)*(twoPiFRC*cosB-sinB)-paramD)+((paramA/denomTwoPiFRC)*((sin(twoPiF*data_inputT[i])*(cosB+twoPiFRC*sinB))+(cos(twoPiF*data_inputT[i])*(sinB-twoPiFRC*cosB))));
    }
}

void RK4CircSim::outputDiffY(){
    for(int i = 0; i < 50; i++){
        data_diffY[i] = (capTimeConst)*(paramD+paramA*sin(twoPiF*data_inputT[i]+paramB)-data_trueY[i]);
    }
}

void RK4CircSim::kValues(){
    for(int i = 0; i < 50; i++){
        rk_k1[i] = data_diffY[i];
       // rk_k2[i] =
    }
}
