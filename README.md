# α-Redis – Moteur de stockage NoSQL In-Memory

Projet académique réalisé dans le cadre du cours **Algorithmique et Structures de Données (ASD)**  
**Licence 3 GLSI – École Supérieure Polytechnique (ESP/UCAD) – Dakar, Sénégal**

---

## Description

**α-Redis** est un moteur de stockage NoSQL de type Clé-Valeur, inspiré de Redis,  
développé entièrement en C++ sans utiliser de structures de données standards.  
Il repose sur une combinaison stricte de :

- Un **tableau dynamique** comme index principal
- Une **table de hachage** avec fonction DJB2
- Des **listes doublement chaînées** pour la gestion des collisions et le type Liste

---

## Architecture
---

## Compilation

```bash
g++ -Wall -std=c++17 -o alpha-redis main.cpp hashtable.cpp list.cpp parser.cpp
```

## Lancement

```bash
./alpha-redis
```

---

## Commandes disponibles

### Opérations sur les chaînes — O(1)

| Commande | Description |
|---|---|
| `SET key value` | Stocke une valeur |
| `GET key` | Récupère une valeur |
| `DEL key` | Supprime une clé |

### Opérations sur les listes — O(1) aux extrémités

| Commande | Description |
|---|---|
| `LPUSH key value` | Insère en tête de liste |
| `RPUSH key value` | Insère en queue de liste |
| `LPOP key` | Extrait en tête de liste |
| `RPOP key` | Extrait en queue de liste |
| `LRANGE key start end` | Affiche les éléments entre start et end |

### Opérations globales

| Commande | Description |
|---|---|
| `KEYS` | Liste toutes les clés stockées |
| `TYPE key` | Retourne le type d'une clé (string/list/none) |
| `FLUSHALL` | Vide toute la base de données |
| `HELP` | Affiche l'aide |
| `EXIT` / `QUIT` | Quitte le programme |

---

## Exemple d'utilisation
---

## Groupe

| Nom | Rôle |
|---|---|
| Baba SIDIBE | Développeur |
| Ndeye Coumba BA | Développeur |
| Mohamed Mourtada CAMARA | Développeur |
| Mariane SECK | Développeur |
| Ndeye Maguette NIANG | Développeur |

---

## Encadrant

**M. Ibrahima GAYE** – ibrahima.gaye.upa@gmail.com

---

## Date de rendu

**Mercredi 05 Juillet 2026**
