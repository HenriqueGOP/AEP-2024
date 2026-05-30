#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

char usuario_cadastrado[50] = "";
char senha_cadastrada[50] = "";
char usuario_login[50];
char senha_login[50];
int tentativas = 0;
int opcao_inicial = 0;
int opcao_menu = 0;

char historico_doencas[5][100] = {"", "", "", "", ""};
int total_triagens = 0;

void limpatela() {
    int i;
    for(i = 0; i < 30; i++) {
        printf("\n");
    }
}

void pausa() {
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

void obterStringSegura(char* buffer, int tamanho) {
    if (fgets(buffer, tamanho, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

int converterParaInteiro(const char* buffer) {
    int resultado = 0;
    int i = 0;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            resultado = resultado * 10 + (buffer[i] - '0');
        } else {
            break;
        }
    }
    return resultado;
}

int obterOpcaoNumerica(const char* pergunta, int min, int max) {
    char buffer[10] = "";
    int opcao = -1;
    
    do {
        printf("%s", pergunta);
        obterStringSegura(buffer, sizeof(buffer));
        opcao = converterParaInteiro(buffer);

        if (opcao < min || opcao > max) {
            printf("Opcao invalida! Escolha um numero entre %d e %d.\n\n", min, max);
        }
    } while (opcao < min || opcao > max);
    
    return opcao;
}

void mostrarCabecalho(const char* titulo) {
    int comprimento = strlen(titulo);
    int espacos_esquerda = (40 - comprimento) / 2;
    int espacos_direita = 40 - comprimento - espacos_esquerda;
    
    printf("\n========================================\n");
    printf("|%*s%s%*s|\n", espacos_esquerda, "", titulo, espacos_direita, "");
    printf("========================================\n");
}

void adicionarAoHistorico(const char* doenca) {
    int i = 0;
    
    if (total_triagens < 5) {
        strcpy(historico_doencas[total_triagens], doenca);
        total_triagens++;
    } else {
        for (i = 0; i < 4; i++) {
            strcpy(historico_doencas[i], historico_doencas[i + 1]);
        }
        strcpy(historico_doencas[4], doenca);
    }
}

void mostrarHistorico() {
    int i = 0;
    
    limpatela();
    mostrarCabecalho("HISTORICO DE TRIAGENS");
    
    if (total_triagens == 0) {
        printf("\nNenhuma triagem realizada ainda.\n");
    } else {
        printf("\nUltimas triagens realizadas:\n\n");
        for (i = 0; i < total_triagens; i++) {
            printf("%d. %s\n", i + 1, historico_doencas[i]);
        }
    }
    pausa();
}

void mostrarDicasPrevencao() {
    limpatela();
    mostrarCabecalho("DICAS DE PREVENCAO");
    
    printf("\nMEDIDAS GERAIS DE PREVENCAO:\n\n");
    printf("- Lave as maos frequentemente com agua e sabao\n");
    printf("- Use alcool em gel 70%% quando nao puder lavar as maos\n");
    printf("- Mantenha os ambientes bem ventilados\n");
    printf("- Evite aglomeracoes em epocas de surto\n");
    printf("- Nao compartilhe objetos pessoais\n\n");
    
    printf("ALIMENTACAO SAUDAVEL:\n\n");
    printf("- Beba pelo menos 2L de agua por dia\n");
    printf("- Consuma frutas ricas em vitamina C\n");
    printf("- Mantenha uma dieta balanceada\n");
    printf("- Evite alimentos ultraprocessados\n\n");
    
    printf("HABITOS SAUDAVEIS:\n\n");
    printf("- Durma 7-8 horas por noite\n");
    printf("- Pratique atividades fisicas regularmente\n");
    printf("- Gerencie o estresse\n");
    printf("- Mantenha as vacinas em dia\n");
    
    pausa();
}

void mostrarContatosEmergencia() {
    limpatela();
    mostrarCabecalho("CONTATOS DE EMERGENCIA");
    
    printf("\nSERVICOS ESSENCIAIS:\n\n");
    printf("- SAMU: 192\n");
    printf("- Bombeiros: 193\n");
    printf("- Policia: 190\n");
    printf("- Disque Saude: 136\n\n");
    
    printf("ORIENTACOES IMPORTANTES:\n\n");
    printf("- Falta de ar: procure atendimento IMEDIATO\n");
    printf("- Febre alta persistente: procure medico\n");
    printf("- Mantenha lista de alergias a medicamentos\n");
    printf("- Tenha contato de familiar sempre a mao\n");
    
    pausa();
}

void mostrarResultadoTriagem(int gravidade, const char* doenca_detectada) {
    printf("\nRESUMO DO SEU QUADRO:\n");
    printf("- Doenca suspeita: %s\n", doenca_detectada);
    printf("- Nivel de gravidade: ");
    
    switch (gravidade) {
        case 0: 
            printf("BAIXA\n"); 
            break;
        case 1: 
            printf("MODERADA\n"); 
            break;
        case 2: 
            printf("ALTA\n"); 
            break;
        case 3: 
            printf("MUITO ALTA\n"); 
            break;
        default:
            printf("BAIXA\n");
            break;
    }

    printf("\nAVISO LEGAL: Este sistema NAO substitui diagnostico medico profissional!\n");
    printf("Consulte sempre um medico para avaliacao adequada.\n");
}

void realizarTriagem() {
    char repetir = 0;
    int febre = 0;
    int doresCorpo = 0;
    int sintomasRespiratorios = 0;
    int dorCabeca = 0;
    int manchasPele = 0;
    int fadiga = 0;
    int dorGarganta = 0;
    int nauseaVomito = 0;
    int faltaAr = 0;
    int contatoRisco = 0;
    int viagem = 0;
    int score_gripe = 0;
    int score_dengue = 0;
    int score_resfriado = 0;
    int score_estresse = 0;
    int score_covid = 0;
    int gravidade = 0;
    char doenca_detectada[100] = "Indisposicao Leve";

    do {
        febre = 0;
        doresCorpo = 0;
        sintomasRespiratorios = 0;
        dorCabeca = 0;
        manchasPele = 0;
        fadiga = 0;
        dorGarganta = 0;
        nauseaVomito = 0;
        faltaAr = 0;
        contatoRisco = 0;
        viagem = 0;
        score_gripe = 0;
        score_dengue = 0;
        score_resfriado = 0;
        score_estresse = 0;
        score_covid = 0;
        gravidade = 0;
        strcpy(doenca_detectada, "Indisposicao Leve");

        limpatela();
        mostrarCabecalho("SISTEMA DE TRIAGEM DE SINTOMAS");
        printf("Responda sobre a intensidade de cada sintoma:\n\n");

        febre = obterOpcaoNumerica("1. Intensidade da febre?\n   (0-Sem, 1-Baixa, 2-Moderada, 3-Alta)\n   Opcao: ", 0, 3);
        doresCorpo = obterOpcaoNumerica("\n2. Intensidade das dores no corpo?\n   (0-Sem, 1-Leve, 2-Moderada, 3-Intensa)\n   Opcao: ", 0, 3);
        dorCabeca = obterOpcaoNumerica("\n3. Intensidade da dor de cabeca?\n   (0-Sem, 1-Leve, 2-Moderada, 3-Intensa)\n   Opcao: ", 0, 3);
        sintomasRespiratorios = obterOpcaoNumerica("\n4. Intensidade dos sintomas respiratorios?\n   (0-Nenhum, 1-Leve, 2-Moderado, 3-Forte)\n   Opcao: ", 0, 3);
        dorGarganta = obterOpcaoNumerica("\n5. Intensidade da dor de garganta?\n   (0-Sem, 1-Leve, 2-Moderada, 3-Intensa)\n   Opcao: ", 0, 3);
        fadiga = obterOpcaoNumerica("\n6. Nivel de fadiga ou cansaço?\n   (0-Nenhum, 1-Leve, 2-Moderado, 3-Intenso)\n   Opcao: ", 0, 3);
        nauseaVomito = obterOpcaoNumerica("\n7. Nauseas ou vomitos?\n   (0-Nao, 1-Ocasional, 2-Frequente)\n   Opcao: ", 0, 2);
        manchasPele = obterOpcaoNumerica("\n8. Manchas na pele?\n   (0-Nao, 1-Poucas, 2-Extensas)\n   Opcao: ", 0, 2);
        faltaAr = obterOpcaoNumerica("\n9. Falta de ar?\n   (0-Nao, 1-Ao esforco, 2-Em repouso)\n   Opcao: ", 0, 2);
        contatoRisco = obterOpcaoNumerica("\n10. Contato com alguem doente?\n   (0-Nao, 1-Suspeito, 2-Confirmado)\n   Opcao: ", 0, 2);
        viagem = obterOpcaoNumerica("\n11. Viajou recentemente?\n   (0-Nao, 1-Sim, 2-Sim area de risco)\n   Opcao: ", 0, 2);

        limpatela();
        mostrarCabecalho("RESULTADO DA TRIAGEM");

        score_gripe = febre * 3 + doresCorpo * 3 + fadiga * 2 + dorCabeca * 2 + sintomasRespiratorios * 2 + dorGarganta;
        score_dengue = febre * 3 + doresCorpo * 3 + dorCabeca * 3 + manchasPele * 5 + nauseaVomito * 4;
        score_resfriado = sintomasRespiratorios * 3 + dorGarganta * 2 + febre + fadiga;
        score_covid = febre * 2 + sintomasRespiratorios * 3 + dorGarganta + fadiga * 2 + faltaAr * 4 + contatoRisco * 3;
        
        if (dorCabeca > 0 && fadiga > 0 && febre == 0) {
            score_estresse = dorCabeca * 2 + fadiga * 2;
        }

        if (faltaAr == 2) {
            printf("ALERTA MAXIMO: BUSQUE ATENDIMENTO DE EMERGENCIA IMEDIATAMENTE!\n\n");
            printf("Doenca: Falta de ar em repouso indica condicao GRAVE\n");
            printf("O que fazer: Dirija-se ao pronto-socorro ou chame SAMU (192)\n");
            printf("Pode indicar: Pneumonia, COVID-19 grave, embolia pulmonar\n");
            strcpy(doenca_detectada, "Emergencia - Falta de Ar");
            gravidade = 3;
        } else if (faltaAr == 1) {
            printf("ALERTA: Consulte um medico URGENTEMENTE\n\n");
            printf("Doenca: Falta de ar ao esforco requer avaliacao\n");
            printf("O que fazer: Procure atendimento nas proximas horas\n");
            strcpy(doenca_detectada, "Urgencia - Falta de Ar");
            gravidade = 2;
        } else if (febre >= 2 && dorCabeca == 3 && nauseaVomito >= 1) {
            printf("ALERTA: BUSQUE UM MEDICO COM URGENCIA!\n\n");
            printf("Suspeita: Meningite ou Dengue Hemorragica\n");
            printf("O que fazer: Avaliacao medica imediata necessaria\n");
            strcpy(doenca_detectada, "Suspeita de Doenca Grave");
            gravidade = 2;
        } else if (score_covid > 15) {
            printf("Suspeita: Possivel COVID-19\n\n");
            printf("Doenca: Combinacao de sintomas sugere COVID-19\n");
            printf("O que fazer: Isole-se, faca teste e monitorize oxigenacao\n");
            printf("Prevencao: Use mascara, evite contato com outras pessoas\n");
            strcpy(doenca_detectada, "Suspeita de COVID-19");
            gravidade = 1;
        } else if (score_dengue > score_gripe && score_dengue > score_resfriado && score_dengue > 12) {
            printf("Suspeita: Alta probabilidade de DENGUE\n\n");
            if (manchasPele) {
                printf("Sinal importante: MANCHAS NA PELE detectadas\n");
            }
            printf("O que fazer: Procure unidade de saude. HIDRATE-SE muito\n");
            printf("NAO TOME: Anti-inflamatorios como ibuprofeno ou aspirina\n");
            printf("Prevencao: Elimine agua parada, use repelente\n");
            strcpy(doenca_detectada, "Suspeita de Dengue");
            gravidade = 1;
        } else if (score_gripe > score_dengue && score_gripe > score_resfriado && score_gripe > 12) {
            printf("Diagnostico: Quadro compativel com GRIPE\n\n");
            if (fadiga == 3) {
                printf("Sintoma marcante: FADIGA INTENSA caracteristica\n");
            }
            printf("O que fazer: Repouso absoluto, hidratacao intensa\n");
            printf("Controle: Medique febre com paracetamol\n");
            printf("Prevencao: Vacinação anual e essencial\n");
            strcpy(doenca_detectada, "Suspeita de Gripe");
            gravidade = 1;
        } else if (score_resfriado > 6) {
            printf("Diagnostico: Provavelmente RESFRIADO COMUM\n\n");
            printf("O que fazer: Repouso relativo, hidratacao normal\n");
            printf("Alivio: Lave narinas com soro fisiologico\n");
            printf("Prevencao: Higiene das maos constante\n");
            strcpy(doenca_detectada, "Resfriado Comum");
            gravidade = 0;
        } else if (score_estresse > 4) {
            printf("Diagnostico: Possivel Cefaleia Tensional/Estresse\n\n");
            printf("O que fazer: Relaxamento, pausas, ambiente calmo\n");
            printf("Alivio: Alongamentos, reduzir tempo em telas\n");
            printf("Importante: Boa higiene do sono\n");
            strcpy(doenca_detectada, "Estresse/Fadiga");
            gravidade = 0;
        } else {
            printf("Situacao: Quadro Inconclusivo ou Indisposicao Leve\n\n");
            printf("O que fazer: Monitorize sintomas, mantenha hidratacao\n");
            printf("Observe: Se surgirem novos sintomas, refaca triagem\n");
            strcpy(doenca_detectada, "Indisposicao Leve");
            gravidade = 0;
        }

        adicionarAoHistorico(doenca_detectada);
        mostrarResultadoTriagem(gravidade, doenca_detectada);

        printf("\nDeseja fazer uma nova triagem? (1-Sim / 0-Nao)\n");
        repetir = obterOpcaoNumerica("Opcao: ", 0, 1);

    } while (repetir == 1);
}

void mostrarCreditos() {
    limpatela();
    mostrarCabecalho("CREDITOS");
    
    printf("\nEste projeto foi desenvolvido como parte da AEP de 2025.\n\n");
    printf("EQUIPE DE DESENVOLVIMENTO:\n\n");
    printf("   - Henrique Gabriel de Oliveira Pereira\n");
    printf("     RA: 25186347-2\n\n");
    printf("   - Murilo Andreotti Borges\n");
    printf("     RA: 25163806-2\n\n");
    printf("   - Micael Martins Fernandes Lima\n");
    printf("     RA: 25362204-2\n\n");
    
    printf("OBJETIVO DO PROJETO:\n");
    printf("   Desenvolver um sistema de triagem de sintomas acessivel\n");
    printf("   e educativo para a populacao em geral.\n\n");
    
    printf("LICENCA: Uso educacional - 2025\n");
    
    pausa();
}

void alterarSenha() {
    char senha_atual[50] = "";
    char nova_senha[50] = "";
    char confirmar_senha[50] = "";
    
    limpatela();
    mostrarCabecalho("ALTERACAO DE SENHA");
    
    printf("\nDigite sua senha atual: ");
    obterStringSegura(senha_atual, sizeof(senha_atual));
    
    if (strcmp(senha_atual, senha_cadastrada) != 0) {
        printf("\nErro: Senha atual incorreta!\n");
        pausa();
        return;
    }
    
    printf("Digite a nova senha: ");
    obterStringSegura(nova_senha, sizeof(nova_senha));
    
    printf("Confirme a nova senha: ");
    obterStringSegura(confirmar_senha, sizeof(confirmar_senha));
    
    if (strcmp(nova_senha, confirmar_senha) != 0) {
        printf("\nErro: As senhas nao coincidem!\n");
    } else if (strlen(nova_senha) < 4) {
        printf("\nErro: A senha deve ter pelo menos 4 caracteres!\n");
    } else {
        strcpy(senha_cadastrada, nova_senha);
        printf("\nSucesso: Senha alterada com sucesso!\n");
    }
    
    pausa();
}

void mostrarEstatisticas() {
    limpatela();
    mostrarCabecalho("ESTATISTICAS DO USUARIO");
    
    printf("\nSUAS ESTATISTICAS:\n\n");
    printf("- Total de triagens realizadas: %d\n", total_triagens);
    
    if (total_triagens > 0) {
        printf("- Ultima triagem: %s\n", historico_doencas[total_triagens - 1]);
        printf("- Primeira triagem do historico: %s\n", historico_doencas[0]);
    }
    
    printf("\nDICAS PERSONALIZADAS:\n\n");
    if (total_triagens == 0) {
        printf("- Faca sua primeira triagem para obter estatisticas\n");
    } else if (total_triagens >= 3) {
        printf("- Voce esta atento a sua saúde! Continue assim\n");
    } else {
        printf("- Considere fazer triagens regulares para monitorar sua saúde\n");
    }
    
    pausa();
}

int main() {
    bool login_sucesso = false;
    
    setlocale(LC_ALL, "Portuguese");

    do {
        limpatela();
        mostrarCabecalho("BEM-VINDO AO SISTEMA DE SAUDE");
        printf("|                                      |\n");
        printf("|   1 - Criar Conta                    |\n");
        printf("|   2 - Fazer Login                    |\n");
        printf("|   3 - Sair                           |\n");
        printf("|                                      |\n");
        printf("========================================\n");
        opcao_inicial = obterOpcaoNumerica("\nEscolha uma opcao: ", 1, 3);

        switch (opcao_inicial) {
            case 1:
                limpatela();
                mostrarCabecalho("CRIACAO DE CONTA");
                printf("\nCrie suas credenciais de acesso:\n\n");
                printf("Digite um nome de usuario: ");
                obterStringSegura(usuario_cadastrado, sizeof(usuario_cadastrado));
                
                if (strlen(usuario_cadastrado) < 3) {
                    printf("Erro: O usuario deve ter pelo menos 3 caracteres!\n");
                    strcpy(usuario_cadastrado, "");
                } else {
                    printf("Digite uma senha: ");
                    obterStringSegura(senha_cadastrada, sizeof(senha_cadastrada));
                    
                    if (strlen(senha_cadastrada) < 4) {
                        printf("Erro: A senha deve ter pelo menos 4 caracteres!\n");
                        strcpy(usuario_cadastrado, "");
                        strcpy(senha_cadastrada, "");
                    } else {
                        printf("\nSucesso: Conta criada com sucesso!\n");
                        printf("Bem-vindo, %s!\n", usuario_cadastrado);
                    }
                }
                pausa();
                break;
                
            case 2:
                if (usuario_cadastrado[0] == '\0') {
                    printf("\nErro: Nenhuma conta encontrada. Crie uma conta primeiro.\n");
                    pausa();
                } else {
                    tentativas = 3;
                    login_sucesso = false;
                    do {
                        limpatela();
                        mostrarCabecalho("LOGIN DE ACESSO");
                        printf("\nPor favor, faca seu login:\n\n");
                        printf("Usuario: ");
                        obterStringSegura(usuario_login, sizeof(usuario_login));
                        printf("Senha: ");
                        obterStringSegura(senha_login, sizeof(senha_login));

                        if (strcmp(usuario_login, usuario_cadastrado) == 0 && 
                            strcmp(senha_login, senha_cadastrada) == 0) {
                            login_sucesso = true;
                            printf("\nSucesso: Login realizado com sucesso!\n");
                            printf("Bem-vindo de volta, %s!\n", usuario_cadastrado);
                            pausa();
                        } else {
                            tentativas--;
                            if (tentativas > 0) {
                                printf("\nErro: Usuario ou senha incorretos! %d tentativa(s) restante(s).\n", tentativas);
                                pausa();
                            }
                        }
                    } while (!login_sucesso && tentativas > 0);

                    if (login_sucesso) {
                        do {
                            limpatela();
                            mostrarCabecalho("MENU PRINCIPAL");
                            printf("|                                      |\n");
                            printf("|   1 - Iniciar Triagem de Sintomas    |\n");
                            printf("|   2 - Ver Historico de Triagens      |\n");
                            printf("|   3 - Estatisticas do Usuario        |\n");
                            printf("|   4 - Dicas de Prevencao             |\n");
                            printf("|   5 - Contatos de Emergencia         |\n");
                            printf("|   6 - Alterar Senha                  |\n");
                            printf("|   7 - Creditos                       |\n");
                            printf("|   8 - Sair do Programa               |\n");
                            printf("|                                      |\n");
                            printf("========================================\n");
                            opcao_menu = obterOpcaoNumerica("\nEscolha uma opcao: ", 1, 8);

                            switch (opcao_menu) {
                                case 1:
                                    realizarTriagem();
                                    break;
                                case 2:
                                    mostrarHistorico();
                                    break;
                                case 3:
                                    mostrarEstatisticas();
                                    break;
                                case 4:
                                    mostrarDicasPrevencao();
                                    break;
                                case 5:
                                    mostrarContatosEmergencia();
                                    break;
                                case 6:
                                    alterarSenha();
                                    break;
                                case 7:
                                    mostrarCreditos();
                                    break;
                                case 8:
                                    printf("\nFazendo logout... Ate logo!\n");
                                    pausa();
                                    break;
                                default:
                                    break;
                            }
                        } while (opcao_menu != 8);
                    } else {
                        limpatela();
                        mostrarCabecalho("ACESSO NEGADO!");
                        printf("\nErro: Voce excedeu o numero de tentativas.\n");
                        printf("Por seguranca, o acesso foi bloqueado.\n");
                        pausa();
                    }
                }
                break;
            case 3:
                printf("\nEncerrando o sistema. Obrigado por usar nosso servico!\n");
                break;
            default:
                break;
        }
    } while (opcao_inicial != 3);

    return 0;
}
