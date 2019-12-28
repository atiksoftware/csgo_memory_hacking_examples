// PositionHead is in screen position X and Y (calculated with word to screen)
float GetPlayerDistanceToCrosshair(Vector2 PositionHead){
	return sqrt(pow((PositionHead.y + 10 - g_pOverlay->screen_centerY), 2) + pow((PositionHead.x - g_pOverlay->screen_centerX), 2));
}
