void CreateAOverlayWindow(){
	LPCWSTR lpClassName = L"AmiralRouterCSGoLiteEspClass";
	LPCWSTR lpWindowName = L"Amiral Router - CSGO Lite ESP";

	overlay_rect = g_pCsgo->GetProcessRect();

	overlay_width = overlay_rect.right - overlay_rect.left;
	overlay_height = overlay_rect.bottom - overlay_rect.top;
	overlay_centerX = overlay_width / 2;
	overlay_centerY = overlay_height / 2;

	HINSTANCE hInstC = GetModuleHandle(0);
	MSG msg;
	long Loops = 0;
	WNDCLASSEX window_class;
	window_class.cbClsExtra = NULL;
	window_class.cbSize = sizeof(WNDCLASSEX);
	window_class.cbWndExtra = NULL;
	window_class.hbrBackground = (HBRUSH)CreateSolidBrush(D3DCOLOR_ARGB(0, 0, 0, 0));
	window_class.hCursor = LoadCursor(0, IDC_ARROW);
	window_class.hIcon = LoadIcon(0, IDI_APPLICATION);
	window_class.hIconSm = LoadIcon(0, IDI_APPLICATION);
	window_class.hInstance = hInstC;
	window_class.lpfnWndProc = WindowProc;
	window_class.lpszClassName = lpWindowName;
	window_class.lpszMenuName = lpWindowName;
	window_class.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClassEx(&window_class);
	overlay_hwnd = CreateWindowEx(
		WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED,
		lpWindowName, lpWindowName,
		WS_POPUP,
		overlay_rect.left, overlay_rect.top, overlay_width, overlay_height,
		0, 0, 0, 0
	);
	SetLayeredWindowAttributes(overlay_hwnd, 0, 255, LWA_ALPHA);
	MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(overlay_hwnd, &margin);

	SetWindowLong(overlay_hwnd, GWL_EXSTYLE, GetWindowLong(overlay_hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);

	ShowWindow(overlay_hwnd, SW_NORMAL);
	UpdateWindow(overlay_hwnd);

}
