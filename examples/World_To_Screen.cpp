// Type of ViewMatrix - 4x4->16 item array, its 64 byte, because of floats 4byte
// ViewMatrix değişken tipi. 4x4->16 elemanlı array. 64 byte boyutunda, çünkü float değerler 4 byte
struct ViewMatrix_t{
	float* operator[ ](int index){
		return matrix[index];
	}
	float matrix[4][4];
};
// you should set ViewMatrix as localplayer viewmatrix as momently
// localplayer viewmatrix i buraya anlık olarak tanımlamalısın
ViewMatrix_t ViewMatrix;

// you give a 3d point coords as xyz, and return a 2d point as xyz. you need x and y. and you should z for element your front or back. if z lower then 0.01f, its mean element back of you. you will not render this.
// 3D noktanın koordinatlarını xyz olarak ver, ve 2D konumlarını xyz oalrak al. X ve Y konumlarına ihtiyacın var. Z konumunu elementin senin önünde mi arkanda mı olduğunu kontrol etmek iin kullanacaksın. eğer Z 0.01f den küçükse element arkandadır. bunu renderlaman gerekmez. 
Vector3 WorldToScreen(Vector3 pos){
	Vector3 result;
	float _x = ViewMatrix[0][0] * pos.x + ViewMatrix[0][1] * pos.y + ViewMatrix[0][2] * pos.z + ViewMatrix[0][3];
	float _y = ViewMatrix[1][0] * pos.x + ViewMatrix[1][1] * pos.y + ViewMatrix[1][2] * pos.z + ViewMatrix[1][3];
	float w = ViewMatrix[3][0] * pos.x + ViewMatrix[3][1] * pos.y + ViewMatrix[3][2] * pos.z + ViewMatrix[3][3];

	float inv_w = 1.f / w;
	_x *= inv_w;
	_y *= inv_w;

	int width = (int)(g_pOverlay->overlay_rect.right - g_pOverlay->overlay_rect.left);
	int height = (int)(g_pOverlay->overlay_rect.bottom - g_pOverlay->overlay_rect.top);

	result.x = width * .5f;
	result.y = height * .5f;

	result.x += 0.5f * _x * width + 0.5f;
	result.y -= 0.5f * _y * height + 0.5f;
	result.z = w;

	return result;
}
