import java.util.Random;
import java.lang.Math;
import java.util.PriorityQueue;
class DnDCharacter {

    // abilities
    private final int strength, dexterity, constitution,
     intelligence, wisdom, charisma;

    private int sumOfLargestThreeDice() {
        Random rand = new Random();
        PriorityQueue<Integer> pqDiceThrows = new PriorityQueue<>();
        for (int i = 0; i < 4; i++) {
            pqDiceThrows.add(rand.nextInt(6) + 1);
        }
        return pqDiceThrows.poll() + pqDiceThrows.poll() + pqDiceThrows.poll();
    }
    public DnDCharacter() {
        strength     = sumOfLargestThreeDice();
        dexterity    = sumOfLargestThreeDice();
        constitution = sumOfLargestThreeDice();
        intelligence = sumOfLargestThreeDice();
        wisdom       = sumOfLargestThreeDice();
        charisma     = sumOfLargestThreeDice();
    }
    
    // random ability
    int ability() {
        Random rand = new Random();
        int choice = 0;
        if((choice = rand.nextInt(6)) == 0) {
            return getStrength();
        } else if (choice == 1) {
            return getDexterity();
        } else if (choice == 2) {
            return getConstitution();
        } else if (choice == 3) {
            return getIntelligence();
        } else if (choice == 4) {
            return getWisdom();
        }
        return getCharisma();
    }

    int modifier(int input) {
        return Math.floorDiv(input - 10, 2);
    }

    int getStrength() {
        return strength;
    }

    int getDexterity() {
        return dexterity;
    }

    int getConstitution() {
        return constitution; 
    }

    int getIntelligence() {
        return intelligence;
    }

    int getWisdom() {
        return wisdom;
    }

    int getCharisma() {
        return charisma;
    }

    int getHitpoints() {
        return 10 + modifier(constitution);
    }

}
