class ArmstrongNumbers {

	boolean isArmstrongNumber(int numberToCheck) {
		int n = numberToCheck;
		int countNumbers = 0;
		int sum = 0;
		while (n != 0) {
			n /= 10;
			countNumbers++;
		}
		n = numberToCheck;
		for (int digit = 0; n != 0 ; n /= 10) {
			digit = n % 10;
			sum += Math.pow(digit, countNumbers);
		}
		return numberToCheck == sum;
	}

}
