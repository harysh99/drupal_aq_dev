<?php

function form_fun_states($form, &$form_state) {
  $form = array();
  $form['#tree'] = TRUE;
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => true,
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['agree'] = array(
    '#type' => 'checkbox',
    '#title' => t('I agree to Terms & Conditions'),

  );
  $form['membership'] = array(
    '#type' => 'fieldset',
    '#title' => t('Members Only'),
    '#states' => array(
      'visible' => array(
      ':input[name="agree"]' => array('checked' => TRUE),
    )
    )
  );
  $form['membership']['cselect'] = array(
    '#type' => 'select',
    '#title' => t('What\'s your favorite'),
    '#options' => array(
      'burger' => t('Burger'),
      'pizza' => t('Pizza'),
    ),
    '#default_value' => 'burger',
  );
  $form['membership']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#required' => true,
    '#size' => 50,
    '#maxlength' => 120,
  );

  return $form;
}
