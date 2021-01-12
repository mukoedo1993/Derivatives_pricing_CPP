
// Author: Dimitri Reiswich

void testingBsPricingEngines1(){
	Real S0=100.0, ST=123;
	Real K1=105.0, K2=112.0;
	Real moneyness=1.10, cash=10.0;

	PlainVanillaPayoff vanillaPayoffCall(Option::Call,K1);
	PlainVanillaPayoff vanillaPayoffPut(Option::Put,K1);
	//
	PercentageStrikePayoff percentagePayoffCall(Option::Call,moneyness);
	PercentageStrikePayoff percentagePayoffPut(Option::Put,moneyness);
	//
	AssetOrNothingPayoff aonPayoffCall(Option::Call,K1);
	AssetOrNothingPayoff aonPayoffPut(Option::Put,K1);
	//
	CashOrNothingPayoff conPayoffCall(Option::Call,K1,cash);
	CashOrNothingPayoff conPayoffPut(Option::Put,K1,cash);
	//
	GapPayoff gapPayoffCall(Option::Call,K1,K2);
	GapPayoff gapPayoffPut(Option::Put,K1,K2);

	std::cout << "S(0):" << S0<< ", S(T):" << ST << std::endl;
	std::cout << "Strike:" << K1 << std::endl;
	std::cout << "Gap Strike:" << K2 << ", Moneyness Strike:"<<moneyness*S0 << std::endl;
	std::cout << "Vanilla Call Payout:" << vanillaPayoffCall(ST) << std::endl;
	std::cout << "Vanilla Put Payout:" << vanillaPayoffPut(ST) << std::endl;
	std::cout << "Percentage Call Payout:" << percentagePayoffCall(ST) << std::endl;
	std::cout << "Percentage Put Payout:" << percentagePayoffPut(ST) << std::endl;
	std::cout << "AON Call Payout:" << aonPayoffCall(ST) << std::endl;
	std::cout << "AON Put Payout:" << aonPayoffPut(ST) << std::endl;
	std::cout << "CON Call Payout:" << conPayoffCall(ST) << std::endl;
	std::cout << "CON Put Payout:" << conPayoffPut(ST) << std::endl;
	std::cout << "Gap Call Payout:" << gapPayoffCall(ST) << std::endl;
	std::cout << "Gap Put Payout:" << gapPayoffPut(ST) << std::endl;
}