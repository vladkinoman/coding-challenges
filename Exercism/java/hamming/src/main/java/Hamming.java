class Hamming {

    private String leftStrand;
    private String rightStrand;
    private int numberOfMutationPoints = 0;

    Hamming(String leftStrand, String rightStrand) {
        if (leftStrand == null)
            throw new IllegalArgumentException("left strand must not be null.");
        else if (rightStrand == null)
            throw new IllegalArgumentException("right strand must not be null.");
        
        if (leftStrand.length() == 0 && rightStrand.length() != 0)
            throw new IllegalArgumentException("left strand must not be empty.");
        else if (leftStrand.length() != 0 && rightStrand.length() == 0)
            throw new IllegalArgumentException("right strand must not be empty.");

        if(leftStrand.length() != rightStrand.length())
            throw new IllegalArgumentException("leftStrand and rightStrand must be of equal length.");

        this.leftStrand = leftStrand;
        this.rightStrand = rightStrand;

        int n = leftStrand.length();
        for (int i = 0; i < n; i++)
            if(leftStrand.charAt(i) != rightStrand.charAt(i))
                numberOfMutationPoints++;
    }

    int getHammingDistance() {
        return numberOfMutationPoints;
    }

}
