ModelInfo_t* pModel = new ModelInfo_t;

	pDevice->GetViewport(&g_ViewPort);
	D3DXMATRIX pProjection, pView, pWorld;
	D3DXVECTOR3 vOut(0, 0, 0), vIn(0, 0, (float)aimheight);

	pDevice->GetVertexShaderConstantF(0, pProjection, 4);
	pDevice->GetVertexShaderConstantF(231, pView, 4);

	D3DXMatrixIdentity(&pWorld);

	D3DXVECTOR3 VectorMiddle(0, 0, 0), ScreenMiddlee(0, 0, 0);
	D3DXVec3Unproject(&VectorMiddle, &ScreenMiddlee, &g_ViewPort, &pProjection, &pView, &pWorld);

	D3DXVec3Project(&vOut, &vIn, &g_ViewPort, &pProjection, &pView, &pWorld);

	float RealDistance = GetDistance(VectorMiddle.x, VectorMiddle.y, vIn.x, vIn.y) / 100;

	if (vOut.z < 1.0f)
	{

		pModel->Position2D.y = vOut.y;
		pModel->Position2D.x = vOut.x;
		pModel->Position2D.z = vOut.z;
		pModel->Distance = RealDistance;
	}

	ModelInfo.push_back(pModel);