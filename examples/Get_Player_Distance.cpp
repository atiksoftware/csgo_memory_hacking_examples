int GetPlayerDistance(Vector3 PlayerOrigin,Vector3 LocalPlayerOrigin){
	return sqrt(pow(PlayerOrigin.x - LocalPlayerOrigin.x, 2) + pow(PlayerOrigin.y - LocalPlayerOrigin.y, 2) + pow(PlayerOrigin.z - LocalPlayerOrigin.z, 2) * 1.0);
}
