<?php

function form_fun_tree() {
  $form = array();
  $form['#tree'] = TRUE;
  $form['home'] = array(
    '#type' => 'fieldset',
    '#title' => 'Home Address',
  );
  $form['home']['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['home']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['home']['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 50,
    '#maxlength' => 120,
  );
$form['office'] = array(
    '#type' => 'fieldset',
    '#title' => 'Office Address',
  );
  $form['office']['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['office']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['office']['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function form_fun_tree_submit($form, &$form_state) {
  dsm($form);
}