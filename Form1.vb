Imports System.IO
Imports System.Net
Imports System.Text

Public Class RaidInjector
    Public ContasCriadas As Integer = 0
    Public Function VerifyResult(ByVal success As Integer, ByVal server_error As Integer, ByVal match_error As Integer, ByVal cookie_error As Integer, ByVal null_parameters As Integer)

        'Verifica resultado'
        If success = 79 Then
            MsgBox("Sucesso!")
        ElseIf server_error = 79 Then
            MsgBox("Parametro e Uid incorretos!")
        ElseIf match_error = 79 Then
            MsgBox("Parametro e Uid incorretos!")
        ElseIf cookie_error = 79 Then
            MsgBox("Parametro Incorreto!")
        ElseIf null_parameters = 0 Or null_parameters = 79 Then
            MsgBox("Preencha todos os campos!")
        Else
            MsgBox("Erro não identificado!")
        End If

    End Function


    Private Sub btnInject_Click(sender As Object, e As EventArgs) Handles btnInject.Click

        Dim URI As String = "http://api2.raidcall.com.ru/feed/im_feed.php"
        Using client As New Net.WebClient
            Dim fileReader As String
            fileReader = My.Computer.FileSystem.ReadAllText("C:\Users\GreTzKi\Desktop\raidcall.txt")

            'Criação de requisição de Param & Uid...'
            Dim reqparm As New Specialized.NameValueCollection
            reqparm.Add("param", txtParam.Text.ToString())
            reqparm.Add("msg", fileReader.ToString())
            reqparm.Add("uid", txtUid.Text.ToString())

            'Realiza upload dos values'
            Dim responsebytes = client.UploadValues(URI, "POST", reqparm)
            Dim responsebody = (New Text.UTF8Encoding).GetString(responsebytes)
            'Retorno de result
            Dim resultSuccess As Integer = InStr(1, responsebody, "success", vbTextCompare)
            Dim resultServerError As Integer = InStr(1, responsebody, "server error: unkown code", vbTextCompare)
            Dim resultPreg_MatchError As Integer = InStr(1, responsebody, "preg_match error", vbTextCompare)
            Dim resultCookieError As Integer = InStr(1, responsebody, "cookie expired", vbTextCompare)
            Dim null_parameters As Integer = InStr(1, responsebody, "null_parameters", vbTextCompare)

            'Callback function result type'
            VerifyResult(resultSuccess, resultServerError, resultPreg_MatchError, resultCookieError, null_parameters)

        End Using

    End Sub

    Private Sub btnCriar_Click(sender As Object, e As EventArgs) Handles btnCriar.Click
        Dim login As String = txtLogin.Text
        Dim senha As String = txtSenha.Text
        Dim email As String = txtEmail.Text
        'Contador
        Dim i As Integer = 0
        'Verifica campos
        If txtLogin.Text = "" Or txtSenha.Text = "" Or txtEmail.Text = "" Then
            MsgBox("Preencha todos os campos!")
        Else
            Dim URI As String = "http://www.raidcall.com.ru/client/fbreg/api.php?"
            Using client As New Net.WebClient

                'Criação de requisição GET
                Dim ac_get As String = "ac=reg_user&"
                Dim name_get As String = "name=" & login & "&"
                Dim email_get As String = "email=" & email & "&"
                Dim pwd_get As String = "pwd=" & senha & "&"
                Dim login_get As String = "login=0&"
                Dim vender_get As String = "vender=default&"
                Dim mid_get As String = "mid=&"
                Dim nick_get As String = "nick=" & login & "&"
                Dim fbid_get As String = "fbid=&"
                Dim fbusername_get As String = "fbusername=&"
                Dim token_get As String = "token="
                'Cria Url p/Get
                Dim UrlFull = URI & ac_get & name_get & email_get & pwd_get & login_get & vender_get & mid_get & nick_get & fbid_get & fbusername_get & token_get

                'Realiza upload dos values'
                Dim responsebytes = client.DownloadString(UrlFull)

                ' Verifica erro
                If responsebytes = "{""error"":403}" Then
                    MsgBox("Conta já existe!")
                ElseIf responsebytes = "{""error"":400}" Then
                    MsgBox("Login inválido. Tente outro!")
                ElseIf responsebytes = "{""error"":405}" Then
                    MsgBox("Login possui caracteres inválidos!")
                ElseIf responsebytes = "{""error"":500}" Then
                    MsgBox("Conta não criada! Modifique seu ip.")
                Else
                    MsgBox("Conta criada com sucesso!")
                    i = ContasCriadas + 1 'Recebe valor de valor atual + 1
                    ContasCriadas = i 'Recebe valor atualizado
                    lblContasCriadas.Text = ContasCriadas 'Add à text o valor total
                End If

            End Using
        End If


    End Sub
End Class
