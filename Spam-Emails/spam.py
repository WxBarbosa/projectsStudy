# -*- coding: utf-8 -*- 
################ #### @Version 1.0! ### #######################
################ #### Sourcer MultSpam #### ###################
#=============================================================#
# Se reaproveitar algo daqui não esqueça dos meus créditos.   #
#=============================================================#
# Todos os direitos reservados à MR.404.                      #
#=============================================================#
#=============================================================#


import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Criando função para alteração de tipo de Servidor de E-mail
def ChangeSMTP(email_type):

    # Variável Global
    global selected_email
    global port
    global mail

    # Verifica escolha
    if email_type == 1:      
        # Autenticação SMTP.
        mail = smtplib.SMTP_SSL('smtp.gmail.com',465)
    elif email_type == 2:
        # Autenticação SMTP.
        mail = smtplib.SMTP('smtp.live.com',25)
        mail.starttls()
        
#Rodape
print('## Para que sua engenharia funcione perfeitamente! ##')
print('## E necessario que o CSS esteja diretamente no elemento HTML ## ')
print('## Nao esqueca de setar todo o caminho aonde se encontram os arquivos (engenharia e lista) ##')
print('## Nao esqueca de preencher todos os dados, para nao ocorrer erros. ##\n')
print('Digite o numero correspondente ao seu e-mail.')
print('  1 - Gmail')
print('  2 - Hotmail')

# Entrada de tipo de E-mail
type_email = int(input('\nSelecione o servidor de E-mail:'))

# Chama função de mudança de SMTP
ChangeSMTP(type_email)

#E-mail
email_user = input('Seu E-mail: ')

# Senha
email_pass = input('Sua senha: ')

# Título.
subject = input('Titulo: ')
 
# Engenharia.
file = str(input('Nome da engenharia: '))
arq = open(file, 'r', encoding='utf-8')
text = arq.read()
arq.close()

# Arquivo E-mail list(Lembre de colocar o diretório completo!!!!).
file = input('Nome da lista de e-mails: ')
 
if not email_user or not email_pass or not subject or not text or not file:
    print('Preencha todos os campos')
    
else:
    # Criando Multipart.
    msg = MIMEMultipart()
    print('Conectando...')
    
    # Leitura de arquivo txt.
    with open(file) as f:
        
        # Realiza a coleta de E-mais linha por linha.
        lines = [line.rstrip('\n') for line in f.readlines()]
    print('Autenticando...')
    # Select de E-mails(realocamento na variável *line*).
    for line in (lines):
        
        # Configuração de Corpo da Mensagem. From(de), To(para), Subject(Título), e Text(Corpo de texto).
        msg['From'] = email_user
        msg['To'] = line
        msg['Subject'] = subject
        msg.attach(MIMEText(text,'html', 'utf-8'))
    

        # Reliza Login.
        mail.ehlo()
        mail.login(email_user, email_pass)

        # Envia E-mails (remetente, destino, corpo de mensagem).
        print('Enviando...')
        mail.sendmail(email_user ,line, msg.as_string())
        print('[Enviado]->' +'('+ line+')')
    print('Pronto. Processo de envio completo')
    mail.close()

