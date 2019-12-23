
#define MAX_FONTS 36
#define MAX_SPRITES 200

LPDIRECT3D9EX d3d;
LPDIRECT3DDEVICE9EX d3ddev;
LPDIRECT3DVERTEXBUFFER9 g_pVB;
LPDIRECT3DINDEXBUFFER9  g_pIB;
ID3DXFont *pFontBold[MAX_FONTS];
ID3DXFont *pFontNormal[MAX_FONTS];

ID3DXFont *fontStratum[MAX_FONTS];
ID3DXFont *fontStratumb[MAX_FONTS];
ID3DXFont *fontCstrike[MAX_FONTS];
ID3DXFont *fontCs[MAX_FONTS];
ID3DXFont *fontCsd[MAX_FONTS];
ID3DXFont *fontToolbox[MAX_FONTS]; 
ID3DXFont *fontTahoma[MAX_FONTS];
ID3DXFont *fontTahomab[MAX_FONTS];
ID3DXFont *fontVerdana[MAX_FONTS];
ID3DXFont *fontVerdanab[MAX_FONTS];
ID3DXFont *fontArial[MAX_FONTS];
ID3DXFont *fontArialb[MAX_FONTS];

LPDIRECT3DTEXTURE9 iconTextures[MAX_SPRITES];
LPD3DXSPRITE iconSprites[MAX_SPRITES];
boolean iconSuccess[MAX_SPRITES];
boolean iconChecked[MAX_SPRITES];


void CreateADirectXDevice(){
	Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d);    // create the Direct3D interface
	if(d3d == NULL){

		std::cout << "Direct3DCreate9 failed" << std::endl;
		return;
	}
	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	D3DCAPS9 caps; int vp = 0;
	if(FAILED(d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps))){

		std::cout << "GetDeviceCaps failed" << std::endl;
		return;
	}
	if(caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = g_pOverlay->overlay_hwnd;    // set the window to be used by Direct3D
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;     // set the back buffer format to 32-bit
	d3dpp.BackBufferWidth = g_pOverlay->overlay_rect.right - g_pOverlay->overlay_rect.left;    // set the width of the buffer
	d3dpp.BackBufferHeight = g_pOverlay->overlay_rect.bottom - g_pOverlay->overlay_rect.top;    // set the height of the buffer

 



	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;



	// create a device class using this information and the info from the d3dpp stuct 
	if(FAILED(d3d->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_pOverlay->overlay_hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, 0, &d3ddev))){
		std::cout << "CreateDevice failed" << std::endl;
		return;
	}

	for(int i = 5; i < MAX_FONTS - 1; i++){
		D3DXCreateFont(d3ddev, i, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Verdana"), &pFontNormal[i]);

		D3DXCreateFont(d3ddev, i, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &fontArial[i]);
		D3DXCreateFont(d3ddev, i, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &fontArialb[i]);

		D3DXCreateFont(d3ddev, i, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Tahoma"), &fontTahoma[i]);
		D3DXCreateFont(d3ddev, i, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Tahoma"), &fontTahomab[i]);

		D3DXCreateFont(d3ddev, i, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Verdana"), &fontVerdana[i]);
		D3DXCreateFont(d3ddev, i, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Verdana"), &fontVerdanab[i]);

		D3DXCreateFont(d3ddev, i, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Stratum2-Bold"), &fontStratum[i]);
		D3DXCreateFont(d3ddev, i, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Stratum2-Bold"), &fontStratumb[i]);

		D3DXCreateFont(d3ddev, i, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("csd"), &fontCsd[i]);
	}


 
}
