set-trace 0
Go
Output-internal ShipsCurrentState (1, (. (. 1, 1,BATTLESHIP, 0,EAST,100,(. 20, 25 .),(: 6, 15, 30, 0 :) .) .)) Main Sim
Go
Output-internal StartSimulation (0) Main Sim
Go
Output-internal OrderSpeedResponse (1, 1) Main Sim
Go
Output-internal OrderSpeedReject (1, 1) Main Sim
Go
Output-internal OrderTurnResponse (1, 1) Main Sim
Go
Output-internal OrderTurnReject (1, 1) Main Sim
Go
Output-internal OrderFireResponse (1, 1) Main Sim
Go
Output-internal OrderFireReject (1, 1) Main Sim
Go
Output-internal ShipsCurrentState (1, (. (. 1, 1, DESTROYER, 0, NORTH_EAST, 50, (. 15, 30 .), (: 0, 30, 6, 0 :) .) .)) Main Sim
Go
Output-internal StartSimulation (0) Main Sim
Go
Output-internal StrategyVictory (1) Main Sim
Go
