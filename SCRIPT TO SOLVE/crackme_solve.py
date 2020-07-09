#!/usr/bin/env python
# -*- coding: utf-8 -*-
from x64dbgpy.pluginsdk import *
import sys

__AUTHOR__ = '@KEOWU - JOÃO FERREIRA'
__COPYRIGHT__ = 'MIT - Open Source'
__VERSION___ = '1'

class whoami(object):
	
	@staticmethod
	def UPX_DETECT_UNPACK():
		gui.Message("INICIANDO O AUTO UNPACK DA APLICAÇÃO")
		debug.SetBreakpoint(0x0000000000513EF5)
		comment.Set(0x0000000000513EF5, "ESSE É O FIM DO UPX PACKER")
		debug.Run()
		debug.SetBreakpoint(0x0000000000401500)
		comment.Set(0x0000000000401500, "ESSE É O OEP DO SEU SOFTWARE")
		debug.Run()
		gui.Message("Agora é com você reconstrua o binário")
		x64dbg.DbgCmdExecDirect("scylla")

	
	@staticmethod
	def PROTECTIONS_REVERSE_ENGINEERING():
		gui.Message("INICIANDO O PROCESSO DE HOOK DE PROTEÇÕES DO BINÁRIO")
		comment.Set(0x000000000040155D, "ESSE É O PRIMEIRO ANTI-DEBUG")
		assembler.AssembleMem(0x0000000000401566, "cmp eax, 0")
		comment.Set(0x0000000000401566, "MODIFICADO PELO SCRIPT")
		
		
	@staticmethod
	def ENCONTRAR_CALCULO_REVERSE_ENGINEERING():
		comment.Set(0x000000000040170D, "CONSTANTE SENDO MOVIDA")
		comment.Set(0000000000401712, "Função de cálculo")
		debug.SetBreakpoint(0x0000000000401664)
		comment.Set(0x0000000000401664, "ACHEI, AQUI OCORRE A COMPARAÇÃO, DO RESULTADO DA OPERAÇÃO MATEMÁTICA")
		if(gui.MessageYesNo("Deseja continuar ? agora o script vaí até o final e irá parar.")):
			debug.DeleteBreakpoint(0x0000000000401664)
			debug.Run()
		else:
			gui.Message("ACABOU :)")
		

whoami().UPX_DETECT_UNPACK()
whoami().PROTECTIONS_REVERSE_ENGINEERING()
whoami().ENCONTRAR_CALCULO_REVERSE_ENGINEERING()