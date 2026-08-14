import numpy as np
import matplotlib.pyplot as plt

# Definindo as constantes 

Rx = 10000          # Resistência do potenciômetro
RL1 = 10 * Rx       # Carga 10x maior que Rx
RL2 = 1 * Rx        # Carga igual a Rx
RL3 = 0.1 * Rx      # Carga 10x menor que Rx 

alpha = np.linspace(0, 1, 11)

# Definindo as funções matemáticas

def ganho_sem_carga(a):
    """ Equação: V0/Vi = alpha """
    return a

def ganho_com_carga(a, Rx, Rl):
    """ Equação: V0/Vi = (alpha * Rl) / (Rl + alpha*Rx - (alpha**2)*Rx) """
    numerador = a * Rl
    denominador = Rl + (a * Rx) - ((a**2) * Rx)
    return numerador / denominador

resultado_sem_carga = ganho_sem_carga(alpha)
resultado_RL1 = ganho_com_carga(alpha, Rx, RL1)
resultado_RL2 = ganho_com_carga(alpha, Rx, RL2)
resultado_RL3 = ganho_com_carga(alpha, Rx, RL3)

plt.figure(figsize=(10, 6))

plt.plot(alpha, resultado_sem_carga, 'green', label='Sem carga', marker='.') 
plt.plot(alpha, resultado_RL1, color='blue', label='Com carga (10x)', marker='.')
plt.plot(alpha, resultado_RL2, color='purple', label='Com carga (1x)', marker='.')
plt.plot(alpha, resultado_RL3, color='yellow', label='Com carga (0.1x)', marker='.')

plt.title('Sensores de potenciômetro com carga e sem carga', fontsize=14)
plt.xlabel('Deslocamento alpha', fontsize=12)
plt.ylabel('Av = V0/Vi', fontsize=12)

plt.grid(True, linestyle='--', alpha=0.7)

plt.legend(loc='upper left')

plt.xlim(-0.05, 1.05)
plt.ylim(-0.05, 1.05)

plt.show()