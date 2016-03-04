#define true 1
#define false 0
#define hand_size 5
typedef int bool;

struct PokerHand{
  char poker_suits[hand_size];
  char poker_ranks[hand_size];
  bool hand[13][4];
};
enum TypeOfHands{
  high_card,
  pair,
  two_pair,
  trips,
  straight,
  flush,
  full_house,
  quads,
  straight_flush
};

struct FinalHand{
  enum TypeOfHands (best_hand);
  char cards[2];
};
