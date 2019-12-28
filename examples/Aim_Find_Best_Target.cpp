int AimFindBestTarget(){
	float targetDistance = 9999.0;

	int bestPlayerIndex = -1;

	for(int i = 0; i < MAX_PLAYERS; i++){
		if(g_pEsp->Players[i].health > 0 && !g_pEsp->Players[i].isAlly && g_pEsp->Players[i].inList && g_pEsp->Players[i].isInScreen){
			g_pEsp->Players[i].ReadCoordOrigin();
			if(g_pEsp->Players[i].distanceCross < 30.f && g_pEsp->Players[i].distanceCross > 0.0f){
				if(g_pEsp->Players[i].distanceCross < targetDistance){
					bestPlayerIndex = i;
					targetDistance = g_pEsp->Players[i].distanceCross;
				}
			}
		}
	}
	return bestPlayerIndex; 
}
