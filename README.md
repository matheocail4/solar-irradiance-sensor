# Projet MINUTO — Mesure de l'irradiance solaire

Projet réalisé dans le cadre du cursus IMT Atlantique (Bretagne-Pays de la Loire, École Mines-Télécom), groupe B24, rendu le 15/01/2025.

**Auteurs :** Aymane Ounzar, Alix Barraque (chef de projet), Nada Aleian, Mathéo Cail, Rémi Leluan, Hugo Bentata

## Objectif

Concevoir et construire, avec du matériel peu onéreux, un capteur solaire simple permettant de mesurer l'irradiance solaire (en W·m⁻²) à Brest dans différentes conditions météorologiques.

## Principe

L'irradiance est déduite de la relation :

```
F☉ = (m × C_T × ΔT) / (S × Δt)
```

où `m` et `S` sont mesurés directement (masse et surface d'un bloc de laiton), et `C_T` (capacité thermique) ainsi que `ΔT/Δt` sont obtenus via :

1. **Étalonnage d'une thermistance** — pont de Wheatstone + carte Arduino + capteur TMP117, pour établir la relation ΔV = f(T).
2. **Mesure de C_T** — chauffage du bloc de laiton par effet Joule (fil de NiCr), suivi de la variation de tension aux bornes de la thermistance.
3. **Mesure de l'irradiance** — exposition du bloc au soleil, mesure de ΔV = f(t), puis conversion en irradiance grâce aux étapes précédentes.

## Résultats

4 mesures effectuées sur 3 jours (12/12/2025, 10/01/2025, 12/01/2025), donnant des valeurs d'irradiance comprises entre **279 W·m⁻²** et **507 W·m⁻²**.

Axes d'amélioration identifiés : prise en compte de l'albédo et des sources de réflexion (mer, bâtiments, nuages), suivi de la trajectoire du soleil pour corriger l'incidence, et isolation thermique plus performante que le polystyrène pour la mesure de C_T.

## Contenu du dépôt

- [`docs/Rapport_MINUTO.pdf`](docs/Rapport_MINUTO.pdf) — rapport complet (démarche, montages, calculs d'incertitude, résultats)
- [`arduino/etalonnage_thermistance.ino`](arduino/etalonnage_thermistance.ino) — lecture de la tension (pont de Wheatstone) et de la température (capteur TMP117), utilisé pour l'étalonnage de la thermistance
- [`arduino/mesure_dV_temps.ino`](arduino/mesure_dV_temps.ino) — mesure de ΔV en fonction du temps sur les pins A0/A1, utilisé pour la mesure de C_T et de l'irradiance
