set-trace 0
Go
Output-internal ShipsCurrentState (1, (. (. 1, 1, MISSILE_CUTTER, 0, SOUTH_WEST, 30, (. 10, 26 .), (: 30, 0, 0, 0 :) .) .)) Main Sim
Go
Output-internal StartSimulation (0) Main Sim
Go
Output-internal DestroyShip (1, 1, MISSILE_CUTTER) Main Sim
Go
Output-internal StrategyLose (1) Main Sim
Go