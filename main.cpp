#include "foodie.h"

int main(int argc, char *argv[]) {

  // TODO make class not need initialization
  LunchMenuChecker lmc;
  lmc.fetchMenu(argc, argv);

  return 0;
}
