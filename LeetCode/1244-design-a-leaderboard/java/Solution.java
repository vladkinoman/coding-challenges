class Leaderboard {

    private class Player {
        private int playerId;
        private List<Integer> score;
        
        public Player(int id, int firstScore) {
            playerId = id;
            score = new ArrayList <Integer>();
            score.add(firstScore);
        }
        
        public int getPlayerId() {
            return playerId;
        }
        
        public List<Integer> getScore() {
            return score;
        }
    } 
    
    private List<Player> lboard;
    
    public Leaderboard() {
        lboard = new ArrayList <Player>();
    }
    
    public void addScore(int playerId, int score) {
        if (playerId < 1 || playerId > 10000) {
            throw new IllegalArgumentException();
        }
        if (score < 1 || score > 100)
            throw new IllegalArgumentException();
        Player player = new Player(playerId, score);
        int playersIndex = lboard.indexOf(player);
        if (playersIndex == -1)
            lboard.add(player);
        else
            lboard.get(playersIndex).getScore().add(score);
    }
    
    public int top(int K) {
        if (1 < K || K > 10000)
            throw new IllegalArgumentException();
        return 0;
    }
    
    public void reset(int playerId) {
        if (playerId < 1 || playerId > 10000) {
            throw new IllegalArgumentException();
        }
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */