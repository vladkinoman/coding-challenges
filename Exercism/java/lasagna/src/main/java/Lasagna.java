public class Lasagna {
  public int expectedMinutesInOven() {
    return 40;
  }

  public int remainingMinutesInOven(int minutesInTheOven) {
    return expectedMinutesInOven() - minutesInTheOven;
  }

  public int preparationTimeInMinutes(int layers) {
    return 2 * layers;
  }

  public int totalTimeInMinutes(int layers, int minutesInTheOven) { 
    return preparationTimeInMinutes(layers) + minutesInTheOven;
  }
}
