#ifndef RK4CIRCUITSIMULATION
#define RK4CIRCUITSIMULATION 1
#define maxLimit 10
#include <fstream>
#include <string>
#include <vector>



using namespace std;

class RK4CircSim
{
  public:
    void setParameters();
    void showData();
    void inputT();
    void outputTrueY();
    void outputDiffY();
    void setStepSize();
    void kValues();

//    double twoPiF(double inputFreq);
//    double stepSize();

  private:
    string userName;
    double paramA, paramB, paramD, paramC, paramR, paramF;
    double inputPeriod;
    double twoPiF, twoPiFRC, denomTwoPiFRC, cosB, sinB, capTimeConst;
    double stepFactor, stepSize;
    vector<double> data_inputT;
    vector<double> data_trueY;
    vector<double> data_diffY;
    vector<double> data_approxY;
    vector<double> rk_phi, rk_k1, rk_k2, rk_k3, rk_k4;

};

#endif

