#pragma once
#include "afxwin.h"


//Validar mail
#include <iostream>
#include <string>
#include <regex>



// Cuadro de diálogo de CRegistro

class CRegistro : public CDialog
{
	DECLARE_DYNAMIC(CRegistro)

public:
	CRegistro(CWnd* pParent = NULL);   // Constructor estándar
	virtual ~CRegistro();

// Datos del cuadro de diálogo
	enum { IDD = IDD_DLG_REGISTRO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	CEdit m_usuario;
	CEdit m_clave;
	CEdit m_confClave;
	CEdit m_nombre;
	CEdit m_direccion;
	CEdit m_telefono;
	CEdit m_celular;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	bool bShiftTab;
	int iFoco;
	int iControles;
	bool validarControl();
public:
	void asignarFoco();
	bool is_email_valid(const std::string& email);
};
