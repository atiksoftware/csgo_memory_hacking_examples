float GetPlayerCalculatedScaleByDistance(int distance){
	if(distance <= 300.0f){
		return 1.0f;
	}
	if(distance >= 1000.0f){
		return 0.5f;
	}
	float dist = distance - 300;
	float oran = dist / 700 * 0.4;
	return 1.0f - oran; 
}
