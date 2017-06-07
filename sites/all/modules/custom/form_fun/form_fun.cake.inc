<?php


/**
 *
 */
function form_fun_cake($form, &$form_state) {
  $form = array();
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => true,
    '#size' => 50,
    '#maxlength' => 120,
  );
  $form['cselect'] = array(
    '#type' => 'select',
    '#title' => t('What\'s your favorite'),
    '#options' => array(
      'burger' => t('Burger'),
      'pizza' => t('Pizza'),
    ),
    '#default_value' => 'burger',
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['buttons']['unsure'] = array(
    '#type' => 'submit',
    '#value' => 'Equivocate',
    '#submit' => array('form_fun_cake_unsure'),
    '#validate' => array(),
  );

  return $form;
}


/***
 *
 */
function form_fun_cake_validate($form, &$form_state) {
  if($form['name']['#value'] == 'admin')
    form_set_error('name', t('Please dont use admin.'));
}

/***
 *

 */
function form_fun_cake_unsure($form, &$form_state) {
  krumo($form['name']['#value']);
  drupal_set_message(t('You have entered @name, in the Name field', array('@name' => $form['name']['#value'])), 'warning');
}

/***
 *
 */
function form_fun_cake_submit($form, &$form_state) {
  dsm($form['name']['#value']);
}
