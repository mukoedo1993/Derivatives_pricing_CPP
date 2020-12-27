//https://www.quantstart.com/articles/Jump-Diffusion-Models-for-European-Options-Pricing-in-C/

/*
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

// Standard normal probability density function
double norm_pdf(const double x) {
    return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
}

// An approximation to the cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double norm_cdf(const double x) {
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - norm_cdf(-x);
    }
}

// This calculates d_j, for j in {1,2}. This term appears in the closed
// form solution for the European call or put price
double d_j(const int j, const double S, const double K, const double r, const double v, const double T) {
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
}

// Calculate the European vanilla call price based on
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double bs_call_price(const double S, const double K, const double r, 
    const double sigma, const double T) {
    return S * norm_cdf(d_j(1, S, K, r, sigma, T))-K*exp(-r*T) * 
        norm_cdf(d_j(2, S, K, r, sigma, T));
}

// Calculate the Merton jump-diffusion price based on 
// a finite sum approximation to the infinite series
// solution, making use of the BS call price.
double bs_jd_call_price(const double S, const double K, const double r, 
    const double sigma, const double T, const int N, const double m, 
    const double lambda, const double nu) {
  double price = 0.0;  // Stores the final call price
  double factorial = 1.0;

  // Pre-calculate as much as possible
  double lambda_p = lambda * m;
  double lambda_p_T = lambda_p * T;

  // Calculate the finite sum over N terms
  for (int n=0; n<N; n++) {
    double sigma_n = sqrt(sigma*sigma + n*nu*nu/T);
    double r_n = r - lambda*(m - 1) + n*log(m)/T;

    // Calculate n!
    if (n == 0) {
      factorial *= 1;
    } else {
      factorial *= n;
    }
    
    // Refine the jump price over the loop
    price += ((exp(-lambda_p_T) * pow(lambda_p_T,n))/factorial) * 
      bs_call_price(S, K, r_n, sigma_n, T);  
  }

  return price;
}

int main(int argc, char **argv) {
    // First we create the parameter list
    double S = 100.0;     // Option price
    double K = 100.0;     // Strike price
    double r = 0.05;      // Risk-free rate (5%)
    double v = 0.2;       // Volatility of the underlying (20%)
    double T = 1.0;       // One year until expiry
    int N = 50;           // Terms in the finite sum approximation
    double m = 1.083287;  // Scale factor for J
    double lambda = 1.0;  // Intensity of jumps
    double nu = 0.4;      // Stdev of lognormal jump process
 
    // Then we calculate the call jump-diffusion value
    double call_jd = bs_jd_call_price(S, K, r, v, T, N, m, lambda, nu);
    std::cout << "Call Price under JD:      " << call_jd << std::endl;

    return 0;
}
*/
