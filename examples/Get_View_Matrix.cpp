// ViewMatrix_t is float array 4x4 => 16 item, 64 byte
ViewMatrix_t GetViewMatrix(){
	ViewMatrix_t ViewMatrix;
	ReadBytes((LPCVOID*)(g_pCsgo->client_dll_base + g_pOffsets->dwViewMatrix), 64, &ViewMatrix);
	return ViewMatrix;
}
