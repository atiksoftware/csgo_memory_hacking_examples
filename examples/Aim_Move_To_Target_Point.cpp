void AimMoveToTargetPoint(int bestPlayerIndex){
	if(bestPlayerIndex < 0) return;
	const float x = g_pEsp->Players[bestPlayerIndex].PositionHeader.x - g_pOverlay->screen_centerX;
	const float y = g_pEsp->Players[bestPlayerIndex].PositionHeader.y - g_pOverlay->screen_centerY;

	std::async([](const float head_x, const float head_y){
		float dx = head_x;
		float dy = head_y;

		INPUT input = { 0 };

		input.mi.dx = dx * (dx > -10 && dx < 10 ? 0.1f : 0.5f);
		input.mi.dy = dy * (dy > -10 && dy < 10 ? 0.1f : 0.5f);

		input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_VIRTUALDESK;
		input.type = INPUT_MOUSE;

		SendInput(1, &input, sizeof INPUT);


		Sleep(1);

	}, x, y);

}
