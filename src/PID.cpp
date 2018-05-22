#include "PID.h"
#include <cmath>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	p_error = 0.0;
	d_error = 0.0;
	i_error = 0.0;

	// Twiddle parameter
	// dp = {0.1 * Kp, 0.1 * Ki, 0.1 * Kd};
	// Kp += dp[0];
	// Ki += dp[1];
	// Kd += dp[2];	

	total_error = 0.0;
	best_error = std::numeric_limits<double>::max();


}

void PID::UpdateError(double cte) {

	// compute the P,I,D errors
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

	total_error += pow(cte,2);

}

// void PID::TuneParameter(double avgerror){
// 	if(avgerror < best_error){
// 		best_error = avgerror;
// 		for(int i = 0; i < dp.size(); i++){
// 			dp[i] *= 1.1;
// 		}
// 	}
// 	else{

// 		for(int i = 0; i < dp.size(); i++){
// 			p[i] -= 2 * dp[i];
// 		}

// 	}

// }

double PID::TotalError() {
	return -PID::Kp * p_error - PID::Ki * i_error - PID::Kd * d_error;
}

