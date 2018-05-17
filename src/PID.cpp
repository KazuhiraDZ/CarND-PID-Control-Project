#include "PID.h"
#include <cmath>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0.0;
	d_error = 0.0;
	i_error = 0.0;

	// Twiddle parameter
	//need_twiddle = false;
	dp = {0.1 * Kp, 0.1 * Ki, 0.1 * Kd};
	step = 1;
	//param_index = 2;
	// the step we start to calculate total_error
	//n_settle_steps = 100;
	// the step we stop loop
	//n_eval_steps = 2000;
	total_error = 0.0;
	best_error = std::numeric_limits<double>::max();
	//tried_adding = false;
	//tried_subtracting = false;

}

void PID::UpdateError(double cte) {
	//if(step == 1){
	//	p_error = cte;
	//}
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

	// update total error only if we're past number of settle steps
	// just like what we did in course
	//if(step % (n_settle_steps + n_eval_steps) > n_settle_steps){
	total_error += pow(cte,2);
	//}

	// last step in twiddle loop
	// if(need_twiddle && step % (n_settle_steps + n_eval_steps) > 0){
	// 	cout << "step: " << step << endl;
	// 	cout << "total error: " << total_error << endl;
	// 	cout << "best error: " << best_error << endl;
	// 	if(total_error < best_error){
	// 		cout << "the best error is improved to " << total_error << " from " << best_error << endl;
	// 		best_error = total_error;
	// 		if(step != n_settle_steps + n_eval_steps){
	// 			dp[param_index]
	// 		} 
	// 	}


	// }



}

double PID::TotalError() {
	return -PID::Kp * p_error - PID::Ki * i_error - PID::Kd * d_error;
}

